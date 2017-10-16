"========================================================================
"Author information
"========================================================================
map <F4> ms:call AddAuthorInfo()<cr>'s

function AddAuthorInfo()
	let n=1
	while n<7
		let line = getline(n)
		if line =~'^\s*>\s*\S*Last\s*modified\s*:\s*\S*.*'
			call UpdateTitle()
			return
		endif
		let n = n + 1
	endwhile
	call AddTitle()
endfunction
function UpdateTitle()
	normal m'
	execute '/> Last modified\s*:/s@:.*$@\=strftime(": %Y-%m-%d %H:%M:%S")@'
	normal "
	normal mk
	execute '/> Filename\s*:/s@:.*$@\=": ".expand("%:t")@'
	execute "noh"
	normal 'k
	echohl WarningMsg | echo "Successful in updating the filename and last modified." | echohl None
endfunction
function AddTitle()
	call append(0,"/**********************************************************")
	call append(1," > Filename     : ".expand("%:t"))
	call append(2," > Author       : Jeyshon<jeyshon@qq.com>")
	call append(3," > Create time  : ".strftime("%Y-%m-%d %H:%M:%S"))"
	call append(4," > Last modified: ".strftime("%Y-%m-%d %H:%M:%S"))
	call append(5,"**********************************************************/")
	echohl WarningMsg | echo "Successful in adding the author information." | echohl None
endfunction
"========================================================================
"normal setting
"========================================================================
"设置行号
set nu
"设置leader键
let mapleader = ','  
let g:mapleader = ','  
"设置鼠标可用
"set mouse=a

"========================================================================
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}
"========================================================================
"ctrlp setting
"========================================================================
Plugin 'kien/ctrlp.vim'  
let g:ctrlp_map = '<leader><leader>'
"let g:ctrlp_cmd = 'CtrlP'
"map <leader>f :CtrlPMRU<CR>
"set wildignore+=*/tmp/*,*.so,*.swp,*.zip     " MacOSX/Linux
"let g:ctrlp_custom_ignore = {
"    \ 'dir':  '\v[\/]\.(git|hg|svn|rvm)$',
"    \ 'file': '\v\.(exe|so|dll|zip|tar|tar.gz)$',
"    \ 'link': 'SOME_BAD_SYMBOLIC_LINKS',
"    \ }
let g:ctrlp_custom_ignore = {
   \ 'file': '\v\.(exe|so|dll|zip|tar|tar.gz|lib|out|png|img|bak|db|o)'
    \ }
" 在每次进行切换分支或者重新设定custome_ignore选项的时候,必须手动清除CtrlP的缓存,
" 也可以使用下句不让它进行缓存处理，但扫描时间会比较耗时
"let g:ctrlp_use_caching = 0
let g:ctrlp_working_path_mode=0
let g:ctrlp_match_window_bottom=1
let g:ctrlp_max_height=15
let g:ctrlp_match_window_reversed=0
let g:ctrlp_mruf_max=500
let g:ctrlp_follow_symlinks=1
nnoremap <leader>b :CtrlPBuffer<CR>
nnoremap <leader>d :CtrlPDir<CR>

"=========================================================================
"youcompleteme setting
"=========================================================================
Plugin 'Valloric/YouCompleteMe'
"let g:ycm_key_list_select_completion=['<c-n>']
"let g:ycm_key_list_previous_completion=['<c-p>']
let g:ycm_global_ycm_extra_conf='/home/jiaxian/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'  
let g:ycm_collect_indentifiers_from_tags_files=1  
let g:ycm_seed_identifiers_with_syntax=1  
" 避免YCM每次加载都对用户提示是否加载  
let g:ycm_confirm_extra_conf=0  
let g:ycm_autoclose_preview_window_after_completion=1  
let g:ycm_complete_in_comments = 1  "在注释输入中也能补全
let g:ycm_complete_in_strings = 1   "在字符串输入中也能补全
let g:ycm_collect_identifiers_from_comments_and_strings = 1   "注释和字符串中的文字也会被收入补全
" 跳到定义或声明  
nnoremap <F2> :YcmCompleter GoToDefinitionElseDeclaration<CR>  
" 强制进行编译  
nnoremap <F5> :YcmForceCompileAndDiagnostics<CR>

"=========================================================================
" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
filetype on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
