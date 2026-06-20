void __usercall sub_1808EC(__int64 a1@<X0>, int a2@<W2>, __int64 a3@<X8>)
{
  int v3; // w9
  __int64 v4; // x29
  int v5; // w21

  *(_QWORD *)(v4 + 24) = a1;
  *(_DWORD *)(v4 - 4) = a2;
  v5 = v3;
  _page_pinner_put_page(a3);
  if ( !v5 )
    JUMPOUT(0x18084C);
  JUMPOUT(0x180864);
}
