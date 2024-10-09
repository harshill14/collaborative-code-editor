const editor = CodeMirror(document.getElementById('editor'), {
    mode: 'text/x-c++src',
    lineNumbers: true
});

const ws = new WebSocket('ws://localhost:9002');

ws.onmessage = (event) => {
    const data = JSON.parse(event.data);
    editor.replaceRange(data.text, data.from, data.to);
};

editor.on('change', (instance, changeObj) => {
    const data = {
        from: changeObj.from,
        to: changeObj.to,
        text: changeObj.text,
        removed: changeObj.removed,
        origin: changeObj.origin
    };
    ws.send(JSON.stringify(data));
});
