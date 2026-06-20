__int64 __fastcall policy_mgr_mlo_sta_set_link_by_linkid(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        signed int a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        unsigned __int8 *a7,
        unsigned __int8 a8,
        unsigned __int8 *a9)
{
  int v17; // w28
  __int64 v18; // x8
  unsigned __int64 v19; // x10
  unsigned int v20; // t1
  __int64 v22; // x9
  unsigned __int64 v23; // x12
  unsigned int v24; // t1
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w7
  __int64 result; // x0
  int v35; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v36; // [xsp+10h] [xbp-20h] BYREF
  __int64 v37; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v38[2]; // [xsp+20h] [xbp-10h] BYREF

  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = a6;
  v36 = 0;
  v37 = 0;
  v35 = 0;
  v38[0] = 0;
  qdf_mem_set(v38, 8u, 0);
  qdf_mem_set(&v37, 8u, 0);
  if ( v17 )
  {
    v18 = a6;
    do
    {
      v20 = *a7++;
      v19 = v20;
      if ( v20 > 0x3F )
        goto LABEL_14;
      --v18;
      *(_DWORD *)((char *)v38 + ((v19 >> 3) & 0x1C)) |= 1 << v19;
    }
    while ( v18 );
  }
  if ( !a8 )
  {
LABEL_9:
    ml_nlink_convert_vdev_bitmap_to_linkid_bitmap(a1, a2, 2, v38, (char *)&v36 + 4, &v35);
    ml_nlink_convert_vdev_bitmap_to_linkid_bitmap(a1, a2, 2, &v37, &v36, &v35);
    if ( a4 > 3 )
    {
      switch ( a4 )
      {
        case 4:
LABEL_21:
          v33 = 4;
          break;
        case 5:
          v33 = 0;
          break;
        case 6:
          if ( a3 == 3 )
            v33 = 0;
          else
            v33 = 3;
          break;
        default:
LABEL_22:
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: Invalid force mode: %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "policy_mgr_mlo_sta_set_link_by_linkid",
            (unsigned int)a4);
          result = 4;
          goto LABEL_26;
      }
    }
    else
    {
      v33 = a4;
      if ( a4 != 1 )
      {
        if ( a4 == 2 )
        {
          v33 = 2 * (a3 != 3);
          goto LABEL_25;
        }
        if ( a4 != 3 )
          goto LABEL_22;
        goto LABEL_21;
      }
    }
LABEL_25:
    result = policy_mgr_mlo_sta_set_nlink(a1, *(unsigned __int8 *)(a2 + 168), a3, a4, a5, WORD2(v36), v36, v33);
    goto LABEL_26;
  }
  v22 = a8;
  while ( 1 )
  {
    v24 = *a9++;
    v23 = v24;
    if ( v24 > 0x3F )
      break;
    --v22;
    *(_DWORD *)((char *)&v38[-1] + ((v23 >> 3) & 0x1C)) |= 1 << v23;
    if ( !v22 )
      goto LABEL_9;
  }
LABEL_14:
  result = 4;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
