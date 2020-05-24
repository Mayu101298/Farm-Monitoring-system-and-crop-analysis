
<!doctype html>
<html>
<head>

<meta charset = "utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<!-- Remember to include the meta viewport tag in your document so mobile devices will render correctly. -->

<link rel="stylesheet" href="./material.min.css">
<script src="./material.min.js"></script>
<link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
<!--
<link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
<link rel="stylesheet" href="https://code.getmdl.io/1.1.3/material.indigo-pink.min.css">
<script defer src="https://code.getmdl.io/1.1.3/material.min.js"></script>
-->
<title>LMS : Log In</title>
<style>
<!-- for Card-->
.demo-card.mdl-card{
	width:512px'
}
.demo-card > .mdl-card__title{
	color:#fff;
	height:176px;
	background:url(abc.jpeg) center/cover;
}
.demo-card > .mdl-card__menu{
	color:#fff;
}
</style>
</head>
<body style="background:#fafafa">

<div class = "mdl-layout mdl-js-layout mdl-layout--fixed-header">
	<!-- Header-->
	<header class="mdl-layout__header">
		<div class="mdl-layout__header-row">
			<span class="mdl-layout-title"> Library Management System</span>
			<div class ="mdl-layout-spacer"> </div>
			<nav class="mdl-navigation mdl-layout--large-screen-only">
				<a class="mdl-navigation__link" href="">About Us</a>
				<a class="mdl-navigation__link" href="">Contact Us</a>
				<a class="mdl-navigation__link" href="">Register</a>
				<a class="mdl-navigation__link" href="">Login</a>
			</nav>
		</div>
	</header>
	<!-- Drawer-->
	<div class="mdl-layout__drawer">
		<span class="mdl-layout-title">Logo</span>
		<nav class ="mdl-navigation">
				<a class="mdl-navigation__link" href="">About Us</a>
				<a class="mdl-navigation__link" href="">Contact Us</a>
				<a class="mdl-navigation__link" href="">Register</a>
				<a class="mdl-navigation__link" href="">Login</a>
		</nav>
	</div>
	<!-- Grid-->
	 <!--<main class="mdl-layout__content">
		<div class="page-content">
			<div class="mdl-grid">
				<div class="mdl-cell mdl-cell--6-col">CS6</div>
				<div class="mdl-cell mdl-cell--4-col">CS4</div>
				<div class="mdl-cell mdl-cell--2-col">CS2</div>
			</div>
		</div>
	 </main>-->


	<main class="mdl-layout__content">
		<div class="page-content">
			<!-- Text Box and Button  and Card AND tABLE-->
			<div class="mdl-grid" >
			<?php
	require 'connect.inc.php';
	if(isset($_POST['submit'])){
		$userid = $_POST['user'];
		$userpass = $_POST['pass'];
		if(!empty($userid) && !empty($userpass)){
			$myQuery = "select t1.librarianname, t2.clginit from librariandetails t1, collegedetails t2 where t1.librarianclgid = t2.clgid AND t2.clginit = '$userid' AND t1.librariancont = '$userpass'";
			$query = mysql_query($myQuery);// or die(mysql_error());
			$row = mysql_fetch_array($query) ;//or die(mysql_error());
			$query_rows = mysql_num_rows($query);
			
			if($query_rows==1 &&!empty($row['librarianname']) AND !empty($row['clginit'])){
				echo '<center><fieldset style="width:30%">SUCCESSFULLY LOGED IN TO USER PROFILE PAGE...<br>';
				echo 'Welcome '.$row['librarianname'].' from '.$row['clginit'];
				echo '<br><a href="library.php"> <b>lets work</b></a></fieldset></center>';
				die();
			}
			else{
				echo "<center>SORRY... YOU ENTERD WRONG USERNAME AND PASSWORD... PLEASE RETRY...</center>";
			}
		}
		else{
			echo '<center>All fields are manadatory.</center>';
		}
	}
?>
			<div class = "mdl-cell mdl-cell--4-col">
				<form method="POST" action="index.php" >
					<div id="Sign-In" align="center">
<fieldset style="width:30%"><legend>LOG-IN HERE</legend>
<form method="POST" action="index.php" style = "border:2 px; background-color: #ffe6e6; padding-top: 50px;  padding-right: 50px;  padding-bottom: 50px;  padding-left: 50px;">
User Id<input class="mdl-textfield__input" type="text" name="user" size="40"><br>
Password<input  class="mdl-textfield__input" type="password" name="pass" size="40"><br>
<input class="mdl-button mdl-js-button mdl-button--raised"  id="button" type="submit" name="submit" value="Log-In">
</form>
</fieldset>
</div>
			<!--		<div class="mdl-textfield mdl-js-textfield">
					<input class="mdl-textfield__input" type="text" id="user"/>
					<label class="mdl-textfield__label" for="username">username</label>
					</div><br>
					<div class="mdl-textfield mdl-js-textfield">
					<input class="mdl-textfield__input" type="password" id="pass"/>
					<label class="mdl-textfield__label" for="password">password</label>
					</div><br>
					<button type="submit" class="mdl-button mdl-js-button mdl-button--raised">Login</button>
				</form>
				-->
			</div>
				<!-- Card -->
				<div class =" mdl-cell mdl-cell--4-col">
					<div class="mdl-card mdl-card-shadow--2dp demo-card">
						<div class="mdl-card__title">
							<h2 class="mdl-card__title-text">Welcome</h2>
						</div>
						<div class="mdl-card__supporting-text">
							Take the tour of the new website.
						</div>
						<div class="mdl-card__actions mdl-card--border">
							<a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect">Get Started</a>
						</div>
						<div class="mdl-card__menu">
							<button class="mdl-button mdl-button--icon mdl-js-button mdl-js-ripple-effect">
								<i class="material-icons">share</i>
							</button>
						</div>
					</div>
				</div>
			
				<!--Table -->
				<div class ="mdl-cell mdl-cell--4-col">
					<table class="mdl-data-table mdl-js-data-table mdl-data-table--select">
					<thead>
					<tr>
						<th class="mdl-data-table__cell--non-numeric">Material</th>
						<th><Quantity/th>
					</tr>
					</thead>
					<tbody>
					<tr>
						<td class="mdl-data-table__cell--non-numeric">MProdct</td>
						<td>
							2345
						</td>
					</tr>
					<tr>
						<td class="mdl-data-table__cell--non-numeric">Prodct</td>
						<td>
							245
						</td>
					</tr>
					</tbody>
					</table>
				</div>
			</div>
		</div>
	</main>

	 <!--footer-->
	 <footer class="mdl-mini-footer">
		<div class="mdl-mini-footer--left-section">
			<div class="mdl-logo">Project by TYFS</div>
			<ul class="mdl-mini-footer--link-list">
				<li><a href = "#">Help</a></li>
				<li><a href = "#">FAQ</a></li>
			</ul>
		</div>
	 </footer>
</div>
</body>
</html>