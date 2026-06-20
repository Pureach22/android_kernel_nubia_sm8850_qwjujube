void __usercall sub_115D98(int a1@<W8>)
{
  _page_pinner_put_page();
  if ( !a1 )
    JUMPOUT(0x115D3C);
  JUMPOUT(0x115D64);
}
