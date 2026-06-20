__int64 __fastcall wlan_hdd_add_vlan(
        __int64 a1,
        _WORD *a2,
        __int64 a3,
        unsigned __int8 a4,
        _BYTE *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x8
  __int64 v14; // x8
  _WORD *v15; // x9
  int v16; // w11
  __int64 v17; // x10
  __int64 v18; // x12
  __int64 result; // x0
  int v20; // w19
  int v21; // w2
  __int64 **v22; // x8
  __int64 v23; // x9
  void (__fastcall *v24)(__int64 **, __int64); // x9
  __int64 v25; // x1
  _BYTE *v26; // x20

  v13 = *(_QWORD *)(a1 + 216);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 80)) == 0 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Unable to get psoc", a6, a7, a8, a9, a10, a11, a12, a13, "wlan_hdd_add_vlan");
    return 4294967274LL;
  }
  v15 = a2 + 941;
  if ( !a2[941] || !a2[942] )
  {
    LODWORD(v17) = 0;
    goto LABEL_22;
  }
  v16 = *(unsigned __int16 *)(a3 + 24);
  v17 = 0;
  v18 = 1;
  if ( (unsigned __int16)a2[941] == v16 || (unsigned __int16)a2[942] == v16 )
    goto LABEL_19;
  if ( !a2[943] || !a2[944] )
  {
    LODWORD(v17) = 2;
    goto LABEL_22;
  }
  v18 = 3;
  v17 = 2;
  if ( (unsigned __int16)a2[943] == v16 || (unsigned __int16)a2[944] == v16 )
    goto LABEL_19;
  if ( !a2[945] || !a2[946] )
  {
    LODWORD(v17) = 4;
    goto LABEL_22;
  }
  v18 = 5;
  v17 = 4;
  if ( (unsigned __int16)a2[945] == v16 || (unsigned __int16)a2[946] == v16 )
  {
LABEL_19:
    v15[v17] = 0;
    v15[v18] = 0;
    goto LABEL_22;
  }
  if ( a2[947] && a2[948] )
  {
    v18 = 7;
    v17 = 6;
    if ( (unsigned __int16)a2[947] != v16 && (unsigned __int16)a2[948] != v16 )
      goto LABEL_23;
    goto LABEL_19;
  }
  LODWORD(v17) = 6;
LABEL_22:
  v20 = v17 + a4;
  if ( (unsigned int)(v20 - 9) < 0xFFFFFFF8 )
  {
LABEL_23:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to find group key mapping for vlan_id: %d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_hdd_add_vlan",
      *(unsigned __int16 *)(a3 + 24));
    return 4294967274LL;
  }
  v21 = *(unsigned __int16 *)(a3 + 24);
  v22 = *(__int64 ***)(v14 + 2808);
  v15[v20 - 1] = v21;
  if ( v21 )
  {
    if ( v22 && *v22 )
    {
      v23 = **v22;
      if ( !v23 )
        goto LABEL_34;
      v24 = *(void (__fastcall **)(__int64 **, __int64))(v23 + 832);
      if ( !v24 )
        goto LABEL_34;
      v25 = *(unsigned __int8 *)(a1 + 168);
      v26 = a5;
      if ( *((_DWORD *)v24 - 1) != 1106321743 )
        __break(0x8229u);
      v24(v22, v25);
    }
    else
    {
      v26 = a5;
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a6, a7, a8, a9, a10, a11, a12, a13, "cdp_set_vlan_groupkey");
    }
    a5 = v26;
  }
LABEL_34:
  result = 0;
  *a5 = v20 + 7;
  return result;
}
