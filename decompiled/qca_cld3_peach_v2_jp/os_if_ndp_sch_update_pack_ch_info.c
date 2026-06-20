__int64 __fastcall os_if_ndp_sch_update_pack_ch_info(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x21
  __int64 v13; // x22
  int v14; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  _WORD *v24; // x24
  unsigned __int64 v25; // x21
  unsigned int *v26; // x25
  __int64 v27; // x26
  __int64 v28; // x27
  int v29; // w8
  _WORD *v30; // x26
  unsigned int v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: num_ch: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "os_if_ndp_sch_update_pack_ch_info",
    *(unsigned int *)(a2 + 20));
  if ( *(_DWORD *)(a2 + 20) )
  {
    v12 = *(_QWORD *)(a1 + 216);
    v13 = *(unsigned int *)(a1 + 208);
    v14 = nla_put(a1, 32794, 0, 0);
    result = 5;
    if ( (v14 & 0x80000000) == 0 )
    {
      v24 = (_WORD *)(v12 + v13);
      if ( v12 + v13 )
      {
        if ( *(_DWORD *)(a2 + 20) )
        {
          v25 = 0;
          v26 = (unsigned int *)(a2 + 40);
          while ( 1 )
          {
            if ( v25 == 4 )
              __break(0x5512u);
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: ch[%d]: freq: %d, width: %d, nss: %d",
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              "os_if_ndp_sch_update_pack_ch_info",
              (unsigned int)v25,
              *(v26 - 2),
              *(v26 - 1),
              *v26);
            v27 = *(_QWORD *)(a1 + 216);
            v28 = *(unsigned int *)(a1 + 208);
            v29 = nla_put(a1, (unsigned int)v25 | 0x8000, 0, 0);
            result = 5;
            if ( v29 < 0 )
              break;
            v30 = (_WORD *)(v27 + v28);
            if ( !v30 )
              break;
            v31 = *(v26 - 2);
            if ( (unsigned int)nla_put(a1, 4, 4, &v31)
              || (v31 = *(v26 - 1), (unsigned int)nla_put(a1, 25, 4, &v31))
              || (v31 = *v26, (unsigned int)nla_put(a1, 23, 4, &v31)) )
            {
              result = 5;
              break;
            }
            ++v25;
            v26 += 5;
            *v30 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v30;
            if ( v25 >= *(unsigned int *)(a2 + 20) )
              goto LABEL_13;
          }
        }
        else
        {
LABEL_13:
          result = 0;
          *v24 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v24;
        }
      }
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
