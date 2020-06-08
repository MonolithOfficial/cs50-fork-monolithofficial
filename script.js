// const str = `[{"title": "article1", "category": "category1", "number": "1"}, 
//             {"title": "article2", "category": "category2", "number": "2"},
//             {"title": "article3", "category": "category3", "number": "3"},
//             {"title": "article4", "category": "category4", "number": "4"},
//             {"title": "article6", "category": "category5", "number": "5"}]`

// jsonData = JSON.parse(str);
// var i;
// output = '';
// for (i = 0; i < jsonData.length; i++){
//     console.log(jsonData[i].title);
//     output += `
//         <div class article number ${jsonData[i].number}>
//             <img src="img/monolith.jpg" alt="article${jsonData[i].number}" title="article${jsonData[i].number}">
//             <p style="color: white">${jsonData[i].title}</p>
//             <p style="color: white">${jsonData[i].category}</p>
//         </div>
//     `
// }

// document.querySelector('#similarArticles').innerHTML = output;
var fileName = location.href.split("/").slice(-1); 
if (fileName[0] == "index.html"){
    console.log(fileName[0]);
}
var jsonToFetch = "top_ten_dm_90s.json";

var k;
var dm_output = '';
fetch('json/'+jsonToFetch)
    .then(data => data.json())
    .then(data => {
        console.log(data);
        for (k = 0; k < data.length; k++){
            // console.log(data[i].title);
            dm_output += `
            <div id="wrapper">
                <h3 class="mainSubTitle">${data[k].place}. ${data[k].name}</h3>
                <p class="desc">${data[k].description}</p>
                <img src="${data[k].photo}" alt="${data[k].name}">
            </div>
            `
        }
        document.querySelector('#wrapperHolder').innerHTML = dm_output;
        document.querySelector('#mainTitleHolder').innerHTML = `<h2 class="mainTitle">${data[0].title}</h2>`;
    });


var i;
var sm_art_output = '';
fetch('json/articles.json')
    .then(data => data.json())
    .then(data => {
        console.log(data);
        for (i = 0; i < data.length; i++){
            console.log(data[i].title);
            sm_art_output += `
            <div class article number ${data[i].number}>
                <img src="img/monolith.jpg" alt="article${data[i].number}" title="article${data[i].number}">
                <p style="color: white">${data[i].title}</p>
                <p style="color: white">${data[i].category}</p>
            </div>
            `
        }
        document.querySelector('#similarArticles').innerHTML = sm_art_output;
    });