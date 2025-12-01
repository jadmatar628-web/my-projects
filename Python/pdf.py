# Rebuild from scratch: Stacked layout (Code block, then Output preview below), full info, clean spacing.

from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Preformatted, Table, TableStyle, PageBreak
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.pagesizes import A4
from reportlab.lib.units import cm
from reportlab.lib import colors

pdf_path = "/mnt/data/I2201A_HTML_Examples_FULL_Stacked.pdf"
doc = SimpleDocTemplate(
    pdf_path, 
    pagesize=A4, 
    title="HTML5 Examples & Output — Lecture 1 (Full, Stacked Layout)",
    leftMargin=1.5*cm, rightMargin=1.5*cm, topMargin=1.5*cm, bottomMargin=1.5*cm
)

styles = getSampleStyleSheet()
H1 = styles["Heading1"]
H2 = styles["Heading2"]
body = ParagraphStyle("body", parent=styles["BodyText"], leading=13, spaceAfter=6)
code_style = ParagraphStyle("code", parent=styles["Code"], fontName="Courier", fontSize=8.6, leading=10.2)

def heading(txt): 
    return Paragraph(txt, H2)

def desc(txt):
    return Paragraph(txt.replace("<", "&lt;").replace(">", "&gt;"), body)

def codeblock(txt):
    return Preformatted(txt, code_style)

def subhead(txt):
    return Paragraph(f"<b>{txt}</b>", body)

content = []
content.append(Paragraph("HTML5 Examples & Output — Lecture 1 (I2201A)", H1))
content.append(Paragraph("Balanced guide with real code followed by a visual output preview for each topic. Pure HTML, no CSS.", body))
content.append(Spacer(1, 0.3*cm))

# Section 1: Basic Structure
content.append(heading("1) Basic Page Structure"))
content.append(desc("Rule: Start with <!DOCTYPE html>, then the root <html> with <head> and <body>. The head holds metadata/title; the body holds visible content."))
code1 = """<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>My First Page</title>
</head>
<body>
  <h1>Hello, World!</h1>
  <p>This is my first web page.</p>
</body>
</html>"""
content.append(subhead("Code"))
content.append(codeblock(code1))
content.append(subhead("Rendered Output"))
content.append(Paragraph("<font size=14><b>Hello, World!</b></font>", body))
content.append(Paragraph("This is my first web page.", body))
content.append(Spacer(1, 0.4*cm))

# Section 2: Head Elements
content.append(heading("2) Head Elements (<title>, <meta>, <style>, <script>)"))
content.append(desc("Rule: Head config does not directly render in the body. Title appears in the browser tab; meta describes the page; script/style affect behavior/presentation."))
code2 = """<head>
  <meta name="description" content="HTML tutorial">
  <meta name="author" content="Ali Ghorayeb">
  <title>HTML Head Example</title>
  <style> body { background-color: #fafafa; } </style>
  <script> console.log('Head loaded'); </script>
</head>"""
content.append(subhead("Code"))
content.append(codeblock(code2))
content.append(subhead("Rendered Output"))
content.append(Paragraph("No direct body output. Effects:", body))
content.append(Paragraph("• Title visible on tab/window.", body))
content.append(Paragraph("• CSS sets page background.", body))
content.append(Paragraph("• Script runs in console.", body))
content.append(Spacer(1, 0.4*cm))

# Section 3: Text & Headings
content.append(heading("3) Text & Headings"))
content.append(desc("Rule: Use semantic text elements: <h1>–<h6>, <p>, and inline tags (<b>, <strong>, <i>, <em>, <sub>, <sup>, <code>, <pre>, <blockquote>, <del>)."))
code3 = """<h1>Main Heading</h1>
<h2>Subheading</h2>
<p>This is a <b>bold</b> and <i>italic</i> example.</p>
<p><strong>Strong</strong> and <em>emphasized</em> text convey meaning.</p>
<p>Water formula: H<sub>2</sub>O. Einstein: E = mc<sup>2</sup></p>
<blockquote cite="http://example.com">This is a quoted block.</blockquote>
<code>inline_code();</code>
<pre>
function hello() {
  return "hi";
}
</pre>
<del>Deprecated text</del>"""
content.append(subhead("Code"))
content.append(codeblock(code3))
content.append(subhead("Rendered Output"))
content.append(Paragraph("<font size=14><b>Main Heading</b></font>", body))
content.append(Paragraph("<b>Subheading</b>", body))
content.append(Paragraph("This is a <b>bold</b> and <i>italic</i> example.", body))
content.append(Paragraph("<strong>Strong</strong> and <em>emphasized</em> text convey meaning.", body))
content.append(Paragraph("Water formula: H<sub>2</sub>O. Einstein: E = mc<sup>2</sup>", body))
content.append(Paragraph("“This is a quoted block.”", body))
content.append(Paragraph("inline_code();", body))
content.append(Paragraph("function hello() {", body))
content.append(Paragraph("&nbsp;&nbsp;return \"hi\";", body))
content.append(Paragraph("}", body))
content.append(Paragraph("<strike>Deprecated text</strike>", body))
content.append(Spacer(1, 0.4*cm))

# Section 4: Links & Anchors
content.append(heading("4) Hyperlinks & Named Anchors"))
content.append(desc("Rule: <a href> creates links; target=\"_blank\" opens a new tab; use named anchors to jump within the same page."))
code4 = """<a href="https://www.w3.org" target="_blank" title="Visit W3C">W3C Website</a>
<a name="top"></a>
<p>Scroll down...</p>
<a href="#top">Back to Top</a>"""
content.append(subhead("Code"))
content.append(codeblock(code4))
content.append(subhead("Rendered Output"))
content.append(Paragraph('<font color="blue"><u>W3C Website</u></font> (opens new tab)', body))
content.append(Paragraph("Scroll down...", body))
content.append(Paragraph('<font color="blue"><u>Back to Top</u></font> (jumps to anchor)', body))
content.append(Spacer(1, 0.4*cm))

# Section 5: Images
content.append(heading("5) Images (<img>)"))
content.append(desc("Rule: <img> is an empty tag; always include descriptive alt text. Width/height affect layout; use relative or absolute paths."))
code5 = """<img src="images/logo.png" alt="Company Logo" width="250" height="150" align="right">"""
content.append(subhead("Code"))
content.append(codeblock(code5))
content.append(subhead("Rendered Output"))
img_table = Table([['']], colWidths=[7*cm], rowHeights=[3*cm])
img_table.setStyle(TableStyle([
    ('BOX', (0,0), (-1,-1), 1, colors.HexColor("#555555")),
    ('BACKGROUND', (0,0), (-1,-1), colors.HexColor("#EEEEEE")),
    ('ALIGN', (0,0), (-1,-1), 'CENTER'),
]))
content.append(Paragraph("<b>Simulated image preview (250×150)</b>", body))
content.append(img_table)
content.append(Paragraph("Alt text: Company Logo", body))
content.append(Spacer(1, 0.4*cm))

# Section 6: Lists
content.append(heading("6) Lists: Ordered, Unordered, Definition"))
content.append(desc("Rule: Use <ol> for ordered (type: 1|A|a|I|i), <ul> for unordered (type: disc|circle|square), and <dl>/<dt>/<dd> for definitions."))
code6 = """<ol type="A">
  <li>First</li>
  <li>Second</li>
</ol>
<ul type="square">
  <li>Apple</li>
  <li>Banana</li>
</ul>
<dl>
  <dt>HTML</dt><dd>HyperText Markup Language</dd>
  <dt>CSS</dt><dd>Cascading Style Sheets</dd>
</dl>"""
content.append(subhead("Code"))
content.append(codeblock(code6))
content.append(subhead("Rendered Output"))
content.append(Paragraph("A. First", body))
content.append(Paragraph("B. Second", body))
content.append(Paragraph("• Apple", body))
content.append(Paragraph("• Banana", body))
content.append(Paragraph("HTML — HyperText Markup Language", body))
content.append(Paragraph("CSS — Cascading Style Sheets", body))
content.append(Spacer(1, 0.4*cm))

# Section 7: Tables
content.append(heading("7) Tables"))
content.append(desc("Rule: Structure tabular data with <table>, <tr>, <th>, <td>. Use <caption>, and group with <thead>, <tbody>, <tfoot>. Merge with colspan/rowspan."))
code7 = """<table border="1">
  <caption>Student Grades</caption>
  <thead>
    <tr><th>Name</th><th>Score</th></tr>
  </thead>
  <tbody>
    <tr><td>Ali</td><td>95</td></tr>
    <tr><td>Lina</td><td>88</td></tr>
  </tbody>
  <tfoot>
    <tr><td colspan="2">End of Table</td></tr>
  </tfoot>
</table>"""
content.append(subhead("Code"))
content.append(codeblock(code7))
content.append(subhead("Rendered Output"))
table_data = [["Name", "Score"], ["Ali", "95"], ["Lina", "88"], ["End of Table",""]]
t = Table(table_data, colWidths=[7*cm, 3*cm])
t.setStyle(TableStyle([
    ('BACKGROUND', (0,0), (-1,0), colors.HexColor("#2251FF")),
    ('TEXTCOLOR', (0,0), (-1,0), colors.white),
    ('ALIGN', (1,1), (1,2), 'CENTER'),
    ('GRID', (0,0), (-1,-1), 0.6, colors.HexColor("#666666")),
    ('SPAN', (0,3), (1,3)),
    ('BACKGROUND', (0,3), (-1,3), colors.HexColor("#EAF0FF")),
    ('BOX', (0,0), (-1,-1), 1, colors.HexColor("#333333")),
]))
content.append(t)
content.append(Spacer(1, 0.4*cm))

# Section 8: Semantic Structure
content.append(heading("8) Semantic Structure (header, nav, main, article, aside, footer)"))
content.append(desc("Rule: Use semantic containers to give meaning and improve accessibility/SEO."))
code8 = """<header>
  <h1>My Website</h1>
  <nav>
    <a href="index.html">Home</a> |
    <a href="about.html">About</a> |
    <a href="contact.html">Contact</a>
  </nav>
</header>
<main>
  <article>
    <h2>About HTML5</h2>
    <p>HTML5 adds semantic meaning and multimedia support.</p>
  </article>
  <aside>
    <p>Related Links</p>
  </aside>
</main>
<footer>
  <p>&copy; 2025 MySite</p>
</footer>"""
content.append(subhead("Code"))
content.append(codeblock(code8))
content.append(subhead("Rendered Output"))
layout = Table([
    [Paragraph("<b>HEADER</b> — branding & navigation", body)],
    [Paragraph("NAV: Home | About | Contact", body)],
    [Paragraph("<b>MAIN</b> — primary content", body)],
    [Paragraph("ARTICLE: About HTML5 — semantic meaning & multimedia support.", body)],
    [Paragraph("ASIDE: Related Links", body)],
    [Paragraph("<b>FOOTER</b> — © 2025 MySite", body)],
], colWidths=[15*cm])
layout.setStyle(TableStyle([
    ('BOX', (0,0), (-1,-1), 1, colors.HexColor("#333333")),
    ('BACKGROUND', (0,0), (-1,0), colors.HexColor("#FFF3CD")),
    ('BACKGROUND', (0,1), (-1,1), colors.HexColor("#E2F0FF")),
    ('BACKGROUND', (0,2), (-1,4), colors.HexColor("#E8FFF2")),
    ('BACKGROUND', (0,5), (-1,5), colors.HexColor("#FFEAEA")),
    ('LEFTPADDING', (0,0), (-1,-1), 6),
    ('BOTTOMPADDING', (0,0), (-1,-1), 6),
]))
content.append(layout)
content.append(Spacer(1, 0.4*cm))

# Section 9: Forms
content.append(heading("9) Forms"))
content.append(desc("Rule: <form> wraps controls. Use <label for> to connect text to inputs. Group with <fieldset>/<legend>. Useful attributes: required, placeholder, min, max."))
code9 = """<form action="submit.php" method="post">
  <fieldset>
    <legend>Contact Information</legend>

    <label for="name">Name:</label>
    <input type="text" id="name" name="name" required><br><br>

    <label for="email">Email:</label>
    <input type="email" id="email" name="email" placeholder="you@example.com"><br><br>

    <label for="age">Age:</label>
    <input type="number" id="age" name="age" min="18" max="99"><br><br>

    <label>Gender:</label>
    <input type="radio" name="gender" value="m"> Male
    <input type="radio" name="gender" value="f"> Female<br><br>

    <label for="fruit">Favorite Fruit:</label>
    <select id="fruit" name="fruit">
      <option value="apple">Apple</option>
      <option value="banana">Banana</option>
      <option value="orange">Orange</option>
    </select><br><br>

    <label for="msg">Message:</label><br>
    <textarea id="msg" name="msg" rows="4" cols="30"></textarea><br><br>

    <input type="submit" value="Send">
    <input type="reset" value="Clear">
  </fieldset>
</form>"""
content.append(subhead("Code"))
content.append(codeblock(code9))
content.append(subhead("Rendered Output"))
form_table = Table([
    ["Name:", "___________________________"],
    ["Email:", "you@example.com"],
    ["Age:", "[ 18 ]"],
    ["Gender:", "( ) Male    ( ) Female"],
    ["Favorite Fruit:", "[ Apple ▾ ]"],
    ["Message:", "__________________________________\n__________________________________"],
    ["", "[ Send ]   [ Clear ]"],
], colWidths=[5*cm, 10*cm])
form_table.setStyle(TableStyle([
    ('BOX', (0,0), (-1,-1), 0.75, colors.HexColor("#666666")),
    ('INNERGRID', (0,0), (-1,-2), 0.25, colors.HexColor("#AAAAAA")),
    ('BACKGROUND', (0,0), (-1,-1), colors.HexColor("#F8FBFF")),
    ('RIGHTPADDING', (0,0), (-1,-1), 6),
    ('LEFTPADDING', (0,0), (-1,-1), 6),
    ('TOPPADDING', (0,0), (-1,-1), 4),
    ('BOTTOMPADDING', (0,0), (-1,-1), 4),
]))
content.append(form_table)
content.append(Spacer(1, 0.4*cm))

# Section 10: Special Characters
content.append(heading("10) Special Characters & Entities"))
content.append(desc("Rule: Reserved characters must be escaped using entities so the browser doesn’t misinterpret them as markup."))
code10 = """&lt;  →  <   (less than)
&gt;  →  >   (greater than)
&amp;  →  &   (ampersand)
&quot; →  "   (double quote)
&copy; →  ©   (copyright)
&deg;  →  °   (degree)
&nbsp; →  non-breaking space"""
content.append(subhead("Code (entities)"))
content.append(codeblock(code10))
content.append(subhead("Rendered Output"))
content.append(Paragraph("&lt; renders as <", body))
content.append(Paragraph("&gt; renders as >", body))
content.append(Paragraph("&amp; renders as &", body))
content.append(Paragraph("&quot; renders as “ ”", body))
content.append(Paragraph("&copy; renders as ©", body))
content.append(Paragraph("&deg; renders as °", body))
content.append(Paragraph("A&nbsp;B keeps the space (non-breaking).", body))

# Build PDF
doc.build(content)
pdf_path
