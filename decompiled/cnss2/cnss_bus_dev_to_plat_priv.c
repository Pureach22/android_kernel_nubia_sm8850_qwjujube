__int64 __fastcall cnss_bus_dev_to_plat_priv(__int64 a1, __int64 a2)
{
  unsigned __int16 **v2; // x8
  unsigned __int16 *v3; // x8
  bool v4; // zf
  __int64 v6; // x9
  int v7; // w10
  int v8; // w8
  bool v9; // zf

  if ( !a1 )
    return cnss_get_plat_priv((unsigned __int8)a1, a2);
  v2 = *(unsigned __int16 ***)(a1 + 128);
  if ( v2
    && ((v3 = *v2, *v3 == 25456) ? (v4 = *((_BYTE *)v3 + 2) == 105) : (v4 = 0),
        v4
     && (v6 = *(_QWORD *)(a1 + 152)) != 0
     && ((v7 = *v3, v8 = *((unsigned __int8 *)v3 + 2), v7 == 25456) ? (v9 = v8 == 105) : (v9 = 0), v9)) )
  {
    return *(_QWORD *)(v6 + 8);
  }
  else
  {
    return 0;
  }
}
