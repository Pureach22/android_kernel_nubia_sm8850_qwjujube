__int64 __fastcall dp_soc_set_param(
        __int64 a1,
        int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x4
  __int64 v12; // x20
  const char *v14; // x2
  bool v15; // zf
  const char *v16; // x8
  const char *v17; // x8

  v11 = (unsigned int)a2;
  v12 = a1 + 0x4000;
  if ( a2 > 3 )
  {
    if ( a2 > 5 )
    {
      if ( a2 == 6 )
      {
        v15 = a3 == 0;
        v14 = "%s: UMAC HW reset support :%u";
        v11 = !v15;
        *(_BYTE *)(a1 + 20098) = v11;
        goto LABEL_32;
      }
      if ( a2 == 7 )
      {
        v15 = a3 == 0;
        v14 = "%s: Multi rx reorder queue setup support: %u";
        v11 = !v15;
        *(_BYTE *)(a1 + 20100) = v11;
        goto LABEL_32;
      }
LABEL_31:
      v14 = "%s: not handled param %d ";
      goto LABEL_32;
    }
    if ( a2 != 4 )
    {
      v15 = a3 == 0;
      v14 = "%s: Rssi dbm conversion support:%u";
      v11 = !v15;
      *(_BYTE *)(a1 + 20097) = v11;
      goto LABEL_32;
    }
    v11 = a3 & 1;
    *(_BYTE *)(a1 + 20120) = *(_BYTE *)(a1 + 20120) & 0xF7 | (8 * (a3 & 1));
    v16 = "%s: Multi Peer group command support:%d";
    goto LABEL_24;
  }
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      *(_DWORD *)(a1 + 17708) = a3;
      v17 = "%s: Max ast ageout count %u";
      goto LABEL_26;
    }
    v16 = "%s: Eapol over control_port:%d";
    v11 = (unsigned __int8)a3;
    *(_BYTE *)(a1 + 17712) = a3;
LABEL_24:
    v14 = v16;
    goto LABEL_32;
  }
  if ( !a2 )
  {
    v17 = "%s: num_msdu exception_desc %u";
    *(_DWORD *)(a1 + 18816) = a3;
LABEL_26:
    v11 = a3;
    v14 = v17;
    goto LABEL_32;
  }
  if ( a2 != 1 )
    goto LABEL_31;
  if ( (wlan_cfg_is_fst_in_cmem_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0 )
    *(_BYTE *)(v12 + 2616) = a3 != 0;
  v14 = "%s: FW supports CMEM FSE %u";
  v11 = a3;
LABEL_32:
  qdf_trace_msg(0x45u, 5u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "dp_soc_set_param", v11);
  return 0;
}
