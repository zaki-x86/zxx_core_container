# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))


# -- Project information -----------------------------------------------------

project = 'zxx_core_container'
copyright = '2022, M Zaki'
author = 'M Zaki'

# The full version, including alpha/beta/rc tags
release = '0.0.1'


# -- General configuration ---------------------------------------------------

# Install these extensions -- using pip install
# except for 'sphinx_design' as it is builtin
extensions = [
    'breathe',
    'myst_parser',
    'sphinx_design',
    'sphinx.ext.graphviz'
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = []

root_doc = "zxx_core_container/index"

show_authors = True

# -- Breathe configuration --------------------------------------------------


breathe_default_project = 'zxx_core_container'

breathe_projects = {
    breathe_default_project : os.path.abspath("doxygen/xml"),
    }


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'pydata_sphinx_theme'

# The title in the home page
html_title = '<b>zxx::core::container</b> Library'

html_short_title = ""

html_baseurl = "/zxx_core_container/"

# html_logo = None

# html_favicon = None'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

# pydata theme options. See pydata theme website for options
html_theme_options = {
    # Add external links
    "external_links" : [
        {
            "url" : "https://github.com/zaki-x86/zxx_core_container", 
            "name" : "Source Code"
        },
    ],
    
    # Add GitHub URL
    "github_url": "https://github.com/zaki-x86",
    
    # Add icons:
    "icon_links" : [
        
    ],
    
    # Add logo 
    "logo" : {
        
    },
    
    "show_toc_level" : 1,
    
    "footer_items": ["copyright", "last-updated"],
    
    # todo! figure out how to add last updated template
    
    # todo! configure google analytics -- when this thing goes live
    # "google_analytics_id": "UA-XXXXXXX",
}

html_sidebars = {
    # todo!
}

html_show_sourcelink = False

html_context = {
    # "github_url": "https://github.com", # or your GitHub Enterprise interprise
    "github_user": "<zaki-x86>",
    "github_repo": "<https://github.com/zaki-x86/cxx_pro_std_articles>",
    "github_version": "<main>",
    #"doc_path": "<path-from-root-to-your-docs>",
}