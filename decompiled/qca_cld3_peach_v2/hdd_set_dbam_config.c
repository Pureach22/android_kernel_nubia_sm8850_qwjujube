__int64 __fastcall hdd_set_dbam_config(__int64 *a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  const char *v14; // x3
  unsigned int v15; // w1
  unsigned int v16; // w4
  unsigned int v17; // w1

  v2 = *a1;
  v4 = *(_QWORD *)(*a1 + 24);
  if ( !(unsigned int)_wlan_hdd_validate_context(v4, "hdd_set_dbam_config") )
  {
    if ( *(_DWORD *)(v4 + 1248) > 1u )
    {
      v16 = *(unsigned __int8 *)(a2 + 4);
      if ( v16 < 3 )
      {
        v17 = *(unsigned __int8 *)(a2 + 4);
        *(_BYTE *)(v2 + 52825) = 1;
        *(_DWORD *)(v4 + 8216) = v16;
        return hdd_send_dbam_config(v2, v17);
      }
      v13 = "%s: Invalid dbam config mode %d";
      v14 = "hdd_convert_qca_dbam_config_mode";
      v15 = 2;
    }
    else
    {
      v13 = "%s: Num of chains [%u] < 2, DBAM config is not allowed";
      v14 = "hdd_set_dbam_config";
      v15 = 8;
    }
    qdf_trace_msg(0x33u, v15, v13, v5, v6, v7, v8, v9, v10, v11, v12, v14);
  }
  return 4294967274LL;
}
