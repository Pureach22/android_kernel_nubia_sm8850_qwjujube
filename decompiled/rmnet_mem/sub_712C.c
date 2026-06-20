void __usercall sub_712C(int a1@<W8>)
{
  _page_pinner_put_page();
  if ( !a1 )
    JUMPOUT(0x70F4);
  JUMPOUT(0x70F8);
}
