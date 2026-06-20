__int64 __fastcall hdd_set_eht_emlsr_links(
        __int64 *a1,
        _WORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x27
  _QWORD *v11; // x28
  const char *v12; // x2
  unsigned int v13; // w1
  __int64 result; // x0
  unsigned int v15; // w21
  unsigned int v16; // w19
  unsigned __int16 v17; // w20
  unsigned __int16 *v18; // x22
  __int64 v19; // x8
  unsigned int v20; // w8
  unsigned __int64 v21; // x21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x23
  unsigned __int8 v31; // w20
  __int64 v32; // x8
  unsigned __int16 v33; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v34; // [xsp+10h] [xbp-40h] BYREF
  __int64 v35; // [xsp+18h] [xbp-38h]
  __int64 v36; // [xsp+20h] [xbp-30h]
  __int64 v37; // [xsp+28h] [xbp-28h] BYREF
  int v38; // [xsp+30h] [xbp-20h]
  __int64 v39; // [xsp+38h] [xbp-18h] BYREF
  __int64 v40; // [xsp+40h] [xbp-10h]
  __int64 v41; // [xsp+48h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v33 = 0;
  v39 = 0;
  v40 = 0;
  v11 = *(_QWORD **)(v10 + 24);
  v38 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  if ( !a2 || *(_DWORD *)(v10 + 40) )
  {
    v12 = "%s: attr NULL or not in STA mode";
    goto LABEL_4;
  }
  v15 = (unsigned __int16)(*a2 - 4);
  if ( v15 < 4 )
  {
    v21 = 0;
    v16 = 0;
  }
  else
  {
    v16 = 0;
    v17 = 0;
    v18 = a2 + 2;
    do
    {
      v20 = *v18;
      if ( v20 < 4 || v15 < v20 )
        break;
      if ( (unsigned int)_nla_parse(&v34, 2, v18, v15, &wlan_emlsr_info_policy, 31, 0) )
      {
        v12 = "%s: Invalid attr";
LABEL_4:
        v13 = 2;
LABEL_5:
        qdf_trace_msg(0x33u, v13, v12, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_eht_emlsr_links");
        result = 4294967274LL;
        goto LABEL_6;
      }
      if ( v35 )
      {
        if ( *(_BYTE *)(v35 + 4) )
        {
          if ( *(_BYTE *)(v35 + 4) == 1 )
          {
            v16 = 2;
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Invalid EMLSR action mode",
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              "hdd_get_cfg_emlsr_mode");
            v16 = 0;
          }
        }
        else
        {
          v16 = 1;
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: EMLSR operation: %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "hdd_set_eht_emlsr_links",
          v16);
      }
      if ( v36 )
      {
        v17 = *(_WORD *)(v36 + 4);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: EMLSR link bitmap: %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "hdd_set_eht_emlsr_links",
          v17);
      }
      v19 = (*v18 + 3) & 0x1FFFC;
      v15 -= v19;
      v18 = (unsigned __int16 *)((char *)v18 + v19);
    }
    while ( (int)v15 > 3 );
    v21 = v17;
  }
  mlo_sta_get_vdev_list(*(_QWORD *)(*(_QWORD *)(v10 + 52832) + 32LL), &v33, &v39);
  v30 = 0;
  v31 = 0;
  do
  {
    if ( ((v21 >> v30) & 1) == 0 )
      goto LABEL_27;
    if ( v33 )
    {
      v32 = v39;
      if ( v39 && v30 == *(unsigned __int8 *)(v39 + 93) )
      {
LABEL_35:
        if ( v31 > 2u )
          goto LABEL_49;
        qdf_mem_copy((char *)&v37 + 6 * v31++, (const void *)(v32 + 74), 6u);
        goto LABEL_26;
      }
      if ( v33 != 1 )
      {
        v32 = v40;
        if ( v40 && v30 == *(unsigned __int8 *)(v40 + 93) )
          goto LABEL_35;
        if ( v33 != 2 )
          goto LABEL_49;
      }
    }
LABEL_26:
    if ( v31 > 1u )
      break;
LABEL_27:
    ++v30;
  }
  while ( v30 != 16 );
  if ( v33 )
  {
    mlo_release_vdev_ref(v39);
    if ( v33 >= 2u )
    {
      mlo_release_vdev_ref(v40);
      if ( v33 > 2u )
LABEL_49:
        __break(0x5512u);
    }
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: number of links to force enable: %d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "hdd_set_eht_emlsr_links",
    v31);
  if ( !v31 )
  {
    v12 = "%s: No links to force EMLSR on";
    v13 = 8;
    goto LABEL_5;
  }
  if ( v16 == 2 )
  {
    ml_nlink_vendor_command_set_link(*v11, *(unsigned __int8 *)(*(_QWORD *)(v10 + 52832) + 8LL), 0, 7, 0, 0, 0, 0);
  }
  else if ( v16 == 1 )
  {
    sme_activate_mlo_links(v11[2], *(unsigned __int8 *)(*(_QWORD *)(v10 + 52832) + 8LL));
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid case", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_eht_emlsr_links");
  }
  result = 0;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
