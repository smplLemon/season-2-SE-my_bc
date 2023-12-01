# season-2-SE-my_bc
<div class="card-block">
<div class="row">
<div class="col tab-content">
<div class="tab-pane active show" id="subject" role="tabpanel">
<div class="row">
<div class="col-md-12 col-xl-12">
<div class="markdown-body">
<p class="text-muted m-b-15">
</p><h1>My Bc</h1>
<p>Remember to git add &amp;&amp; git commit &amp;&amp; git push each exercise!</p>
<p>We will execute your function with our test(s), please DO NOT PROVIDE ANY TEST(S) in your file</p>
<p>For each exercise, you will have to create a folder and in this folder, you will have additional files that contain your work. Folder names are provided at the beginning of each exercise under <code>submit directory</code> and specific file names for each exercise are also provided at the beginning of each exercise under <code>submit file(s)</code>.</p>
<hr>
<table>
<thead>
<tr>
<th>My Bc</th>
<th></th>
</tr>
</thead>
<tbody>
<tr>
<td>Submit directory</td>
<td>.</td>
</tr>
<tr>
<td>Submit files</td>
<td>Makefile - *.c - *.h</td>
</tr>
</tbody>
</table>
<h3>Description</h3>
<h1>Command Name</h1>
<p>Write a programm called <code>my_bc</code>. Following the specifications of this man page.</p>
<h2>SYNOPSIS</h2>
<p>my_bc "1 + 2 * (3 - 42) / 5"</p>
<h2>DESCRIPTION</h2>
<p>A valid expression:</p>
<ul>
<li>• must only contain the operators +, -, *, /, and modulo (percent)</li>
<li>• must only have integer values</li>
<li>• can contain parentheses, but each group must be properly closed</li>
<li>• can contain spaces</li>
</ul>
<p>Since we are doing whole number arithmetic, divisions are euclidian keeping only the quotient, while the remainder can be obtained with a modulo operation.</p>
<h2>Requirements</h2>
<ul>
<li>Your code must be compiled with the flags <strong>-Wall -Wextra -Werror</strong>.</li>
</ul>
<h2>Hint(s)</h2>
<ul>
<li>Watch out for <strong>memory leaks</strong> !</li>
<li>You can test your code against memory errors by compiling with the debugging flags <strong>-g3 -fsanitize=address</strong>
</li>
</ul>
<h2>Technical Information</h2>
<ol>
<li>you must create a Makefile, and the ouput is the command itself</li>
<li>You can use:</li>
</ol>
<ul>
<li>• malloc(3)</li>
<li>• free(3)</li>
<li>• printf(3)</li>
<li>• write(2)</li>
</ul>
<ol start="3">
<li>You can NOT use:</li>
</ol>
<ul>
<li>• Any functions / syscalls which does not appear in the previous list</li>
<li>• Yes, it includes <strong>exit</strong>
</li>
<li>Multiline macros are forbidden</li>
<li>Include another .c is forbidden</li>
<li>Macros with logic (while/if/variables/...) are forbidden</li>
</ul>
<ol start="4">
<li>Errors handling:
You will display them on stderr and return exit failure status code.</li>
</ol>
<ul>
<li>If you can't parse the expression you will display: parse error</li>
<li>Divide by zero is an error that you will display: divide by zero</li>
</ul>
<ol start="5">
<li>Algorithm:
You will implement those algorithms shunting-yard (or called the reverse-polish) :-)</li>
</ol>
<h2>Example 00</h2>
<pre class=" language-plain"><code class=" language-plain">$&gt;./my_bc "312/0"
divide by zero
$&gt;
</code></pre>
<h2>Example 01</h2>
<pre class=" language-plain"><code class=" language-plain">$&gt;./my_bc "321()"
parse error
$&gt;
</code></pre>
<h2>Example 02</h2>
<pre class=" language-plain"><code class=" language-plain">$&gt;./my_bc "-(-((-4)+-6))"
-10
$&gt;
</code></pre>

<p></p>
</div>

</div>
</div>
</div>
<div class="tab-pane" id="resources" role="tabpanel">
</div>
</div>
</div>
</div>
