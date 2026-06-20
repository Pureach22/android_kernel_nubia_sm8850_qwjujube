void __usercall sub_28D5D8(__int64 a1@<X8>, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int v4; // w9
  int v5; // w20
  int v6; // w22

  if ( v4 > 4 )
LABEL_10:
    __break(0x5512u);
  if ( *(unsigned __int8 *)(a1 + 36LL * v4 + 12) != v6 )
  {
    if ( v5 == 3 )
      goto LABEL_12;
    if ( HIDWORD(a3) > 4 )
      goto LABEL_10;
    if ( *(unsigned __int8 *)(a1 + 36LL * HIDWORD(a3) + 12) != v6 )
    {
      if ( v5 == 4 )
        goto LABEL_12;
      if ( a4 > 4 )
        goto LABEL_10;
      if ( *(unsigned __int8 *)(a1 + 36LL * a4 + 12) != v6 )
      {
        if ( v5 != 5 )
          goto LABEL_10;
LABEL_12:
        JUMPOUT(0x28D4A0);
      }
    }
  }
  JUMPOUT(0x28D594);
}
