__int64 __fastcall lim_upt_mlo_partner_info(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        unsigned __int16 a4,
        unsigned __int16 a5)
{
  __int64 v5; // x24
  int v8; // w25
  int v10; // w19
  __int64 result; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w9
  __int64 v26; // x20
  unsigned __int64 v27; // x26
  __int64 v28; // x23
  unsigned int *v29; // x8
  __int64 v30; // x10
  int v31; // w9
  unsigned int v32; // w13
  unsigned __int8 *v33; // x11
  _DWORD *v34; // x12
  int *v35; // x10
  int v36; // w14
  unsigned __int8 *v37; // x15
  unsigned int v38; // w17
  __int64 v39; // x16
  int v40; // w17
  _DWORD *v41; // x0
  unsigned int v42; // w13
  bool v43; // cf
  __int64 v44; // x16
  int v45; // w12

  v5 = a1 + 12288;
  v8 = *(unsigned __int16 *)(a1 + 12466);
  v10 = (int)a3;
  result = (__int64)wlan_get_ext_ie_ptr_from_ext_id("k", 1u, a3, a4);
  if ( !result )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: no mlo ie in mlo ap vdev id %d",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "lim_upt_mlo_partner_info",
             *(unsigned __int8 *)(a2 + 10));
  v25 = *(unsigned __int8 *)(v5 + 176);
  if ( *(_BYTE *)(v5 + 176) )
  {
    v26 = result;
    v27 = 0;
    v28 = a1 + 12468;
    do
    {
      if ( v27 == 3 )
      {
        __break(0x5512u);
        return sch_append_addn_ie(result, v12, v13, v14, v15, v16);
      }
      v29 = (unsigned int *)(v28 + 32 * v27);
      v30 = *((unsigned __int16 *)v29 + 8);
      if ( *((_WORD *)v29 + 8) )
      {
        if ( (v29[7] & 1) != 0 )
        {
          v31 = *(unsigned __int8 *)(v26 + (unsigned __int16)(v8 + 1));
          v32 = (unsigned __int16)(v31 - v30 + 2);
          v33 = (unsigned __int8 *)(v26 + (unsigned __int16)v8 + v30);
          v34 = v29 + 2;
          v35 = (int *)(v29 + 3);
          if ( v32 >= 2 )
          {
            v36 = 0;
            v37 = v33;
            while ( 1 )
            {
              v38 = *v37;
              v39 = v37[1];
              if ( __PAIR64__(v39, v38) == 0x300000025LL )
              {
                v40 = 4;
                v41 = v29 + 2;
              }
              else
              {
                if ( __PAIR64__(v39, v38) != 0x40000003CLL )
                  goto LABEL_16;
                v40 = 5;
                v41 = v29 + 3;
              }
              *v41 = v40 + v36;
LABEL_16:
              v42 = v32 - 2;
              v43 = v42 >= (unsigned int)v39;
              v32 = v42 - v39;
              if ( v43 )
              {
                v44 = v39 + 2;
                v36 += v44;
                v37 += v44;
                if ( v32 > 1 )
                  continue;
              }
              break;
            }
          }
          if ( *v34 )
          {
            *v34 += (_DWORD)v33 + a5 - v10;
            v45 = *v35;
            if ( *v35 )
              goto LABEL_21;
          }
          else
          {
            v45 = *v35;
            if ( *v35 )
LABEL_21:
              *v35 = v45 + (_DWORD)v33 + a5 - v10;
          }
          v8 += v31 + 2;
          result = qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: vdev %d mlo csa_count_offset %d ecsa_count_offset %d",
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     v23,
                     v24,
                     "lim_upt_mlo_partner_info",
                     *v29);
          v25 = *(unsigned __int8 *)(v5 + 176);
          goto LABEL_5;
        }
        v8 += *(unsigned __int8 *)(v26 + (unsigned __int16)(v8 + 1)) + 2;
      }
LABEL_5:
      ++v27;
    }
    while ( v27 < v25 );
  }
  return result;
}
