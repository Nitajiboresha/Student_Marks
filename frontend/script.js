document.addEventListener('DOMContentLoaded', () => {
    fetch('/api/marks/1')
        .then(response => response.json())
        .then(data => {
            const marksDiv = document.getElementById('marks');
            const table = document.createElement('table');
            const headerRow = document.createElement('tr');
            const headers = ['Name', 'Total', 'Average', 'Status'];
            headers.forEach(headerText => {
                const th = document.createElement('th');
                th.textContent = headerText;
                headerRow.appendChild(th);
            });
            table.appendChild(headerRow);

            const row = document.createElement('tr');
            row.innerHTML = `
                <td>${data.name}</td>
                <td>${data.marks.reduce((a, b) => a + b, 0)}</td>
                <td>${data.marks.reduce((a, b) => a + b, 0) / data.marks.length}</td>
                <td>${data.marks.reduce((a, b) => a + b, 0) / data.marks.length >= 50 ? 'PASS' : 'FAIL'}</td>
            `;
            table.appendChild(row);

            marksDiv.appendChild(table);
        });
});