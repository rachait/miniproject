**Ice-cream Parlor Management System**
This C program implements a simple Ice-cream Parlor Management System, allowing the user to manage a database of ice-cream items. The program provides options to display, add, update, search, and delete ice-cream records.

**Features**
Display Ice-creams List: Shows all the ice-cream items stored in the database, including their ID, name, and price.
Add New Ice-cream: Allows the user to add a new ice-cream to the database with a unique ID, name, and price.
Update Ice-cream Record: Lets the user update an existing ice-cream's name and price using its unique ID.
Search Ice-cream by ID: Enables searching for an ice-cream using its ID to display its details.
Delete Ice-cream Record: Removes an ice-cream from the database by its ID.
Program Structure
**1. struct ice_cream**
This structure holds the details of an ice-cream:

id: a unique identifier for the ice-cream.
name: the name of the ice-cream.
price: the price of the ice-cream.
**2. struct ice_cream_database**
This structure maintains a dynamic array of ice_cream records and a count of the total records.

**3. Functions**
display_ice_creams(struct ice_cream_database *database): Displays the list of ice-creams, showing their IDs, names, and prices.

add_new_ice_cream(struct ice_cream_database *database): Adds a new ice-cream to the database by reallocating memory and updating the array of ice-creams.

update_ice_cream(struct ice_cream_database *database): Updates the details of an ice-cream based on its ID.

search_ice_cream(struct ice_cream_database *database): Searches for an ice-cream in the database using its ID and displays its details.

delete_ice_cream(struct ice_cream_database *database): Deletes an ice-cream record by its ID, reallocating the database array accordingly.

**4. Main Function**
The main() function contains a menu-driven interface that allows the user to choose various actions, such as displaying the ice-cream list, adding, updating, searching, and deleting records.


**Notes**
The ice-cream database is stored in memory. Once the program exits, the data will be lost.
Input validation for price and name is minimal; further validation can be added for a more robust program.
The program dynamically allocates memory using realloc(). Ensure that the system has sufficient memory when adding new records.
