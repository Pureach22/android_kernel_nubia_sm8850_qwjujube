char *__fastcall wlan_mlo_add_t2lm_info_ie(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x19
  char v13; // w8
  __int64 v14; // x22
  __int64 v15; // x23
  _WORD *v16; // x23
  unsigned __int8 v17; // w9
  __int64 v18; // x23
  __int16 v19; // w21
  char v20; // w8
  __int64 v21; // x24
  __int64 cmpt_obj; // x0
  char v23; // w9
  __int64 v24; // x22
  __int64 v25; // x22
  unsigned __int8 v26; // w26
  unsigned int *v27; // x27
  _BYTE *v28; // x21
  __int64 v29; // x24
  __int64 v30; // x8
  __int16 v31; // w8
  __int64 v32; // x24
  __int64 v33; // x8
  char v34; // w9

  *(_WORD *)a1 = 511;
  v12 = a1;
  *(_BYTE *)(a1 + 2) = 109;
  v13 = *((_BYTE *)a2 + 4);
  if ( (v13 & 1) != 0 )
  {
    *(_BYTE *)(a1 + 3) = *(_BYTE *)a2 & 3
                       | (4 * v13)
                       | (8 * *((_BYTE *)a2 + 5))
                       | (16 * *((_BYTE *)a2 + 6))
                       | (32 * *((_BYTE *)a2 + 49));
    *(_BYTE *)(a1 + 1) = 2;
    v14 = jiffies;
    if ( wlan_mlo_add_t2lm_info_ie___last_ticks - jiffies + 125 < 0 )
    {
      v15 = a3;
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: T2LM IE added, default_link_mapping: %d dir:%d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_mlo_add_t2lm_info_ie",
        *((unsigned __int8 *)a2 + 4),
        *a2);
      a3 = v15;
      wlan_mlo_add_t2lm_info_ie___last_ticks = v14;
    }
    v16 = (_WORD *)(v12 + 4);
    goto LABEL_34;
  }
  if ( *((_WORD *)a2 + 16) || *((_WORD *)a2 + 8) )
  {
    v17 = 1;
    if ( *((_WORD *)a2 + 17) )
      goto LABEL_12;
  }
  else
  {
    v17 = 0;
    if ( *((_WORD *)a2 + 17) )
    {
LABEL_12:
      v17 |= 2u;
      if ( !*((_WORD *)a2 + 18) )
        goto LABEL_13;
      goto LABEL_14;
    }
  }
  if ( *((_WORD *)a2 + 9) )
    goto LABEL_12;
  if ( !*((_WORD *)a2 + 18) )
  {
LABEL_13:
    if ( !*((_WORD *)a2 + 10) )
      goto LABEL_15;
  }
LABEL_14:
  v17 |= 4u;
LABEL_15:
  if ( *((_WORD *)a2 + 19) || *((_WORD *)a2 + 11) )
    v17 |= 8u;
  if ( *((_WORD *)a2 + 20) || *((_WORD *)a2 + 12) )
    v17 |= 0x10u;
  if ( *((_WORD *)a2 + 21) || *((_WORD *)a2 + 13) )
    v17 |= 0x20u;
  if ( *((_WORD *)a2 + 22) || *((_WORD *)a2 + 14) )
    v17 |= 0x40u;
  if ( *((_WORD *)a2 + 23) || *((_WORD *)a2 + 15) )
    v17 |= 0x80u;
  v18 = jiffies;
  v19 = *(_BYTE *)a2 & 3
      | (unsigned __int8)(4 * v13)
      | (unsigned __int8)(8 * *((_BYTE *)a2 + 5))
      | (unsigned __int8)(16 * *((_BYTE *)a2 + 6))
      | (unsigned __int8)(32 * *((_BYTE *)a2 + 49))
      | (v17 << 8);
  if ( wlan_mlo_add_t2lm_info_ie___last_ticks_45 - jiffies + 125 < 0 )
  {
    v21 = a3;
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: T2LM IE added, direction:%d link_mapping_presence_indicator:%x",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_mlo_add_t2lm_info_ie");
    wlan_mlo_add_t2lm_info_ie___last_ticks_45 = v18;
    a3 = v21;
    v20 = *(_BYTE *)(v12 + 1) + 2;
  }
  else
  {
    v20 = 3;
  }
  v16 = (_WORD *)(v12 + 5);
  *(_WORD *)(v12 + 3) = v19;
  *(_BYTE *)(v12 + 1) = v20;
LABEL_34:
  if ( *((_BYTE *)a2 + 5) == 1 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a3, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( !cmpt_obj )
    {
      qdf_trace_msg(0x99u, 2u, "%s: null vdev_mlme", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_mlo_add_t2lm_info_ie");
      return (char *)v12;
    }
    v23 = *(_BYTE *)(v12 + 1);
    *v16++ = *(_WORD *)(cmpt_obj + 40);
    *(_BYTE *)(v12 + 1) = v23 + 2;
  }
  if ( *((_BYTE *)a2 + 6) == 1 )
  {
    qdf_mem_copy(v16, a2 + 3, 3u);
    v16 = (_WORD *)((char *)v16 + 3);
    *(_BYTE *)(v12 + 1) += 3;
  }
  v24 = jiffies;
  if ( wlan_mlo_add_t2lm_info_ie___last_ticks_48 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: mapping_switch_time:%d expected_duration:%u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_mlo_add_t2lm_info_ie",
      *((unsigned __int16 *)a2 + 4),
      a2[3]);
    wlan_mlo_add_t2lm_info_ie___last_ticks_48 = v24;
    if ( (a2[1] & 1) != 0 )
      return (char *)v16;
  }
  else if ( (a2[1] & 1) != 0 )
  {
    return (char *)v16;
  }
  v25 = 0;
  v26 = 0;
  v27 = a2 + 4;
  v28 = v16;
  do
  {
    v31 = *((_WORD *)v27 + v25);
    if ( v31 )
    {
      if ( (*((_BYTE *)a2 + 49) & 1) != 0 )
      {
        *v28 = v31;
        v29 = jiffies;
        if ( wlan_mlo_add_t2lm_info_ie___last_ticks_51 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x99u,
            8u,
            "%s: link mapping of TID%d is %x",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "wlan_mlo_add_t2lm_info_ie",
            (unsigned int)v25,
            *((unsigned __int16 *)v27 + v25));
          wlan_mlo_add_t2lm_info_ie___last_ticks_51 = v29;
        }
        v30 = 1;
      }
      else
      {
        *(_WORD *)v28 = v31;
        v32 = jiffies;
        if ( wlan_mlo_add_t2lm_info_ie___last_ticks_50 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x99u,
            8u,
            "%s: link mapping of TID%d is %x",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "wlan_mlo_add_t2lm_info_ie",
            (unsigned int)v25,
            *((unsigned __int16 *)v27 + v25));
          wlan_mlo_add_t2lm_info_ie___last_ticks_50 = v32;
        }
        v30 = 2;
      }
      v28 += v30;
      ++v26;
    }
    ++v25;
  }
  while ( v25 != 8 );
  v33 = v26;
  if ( (*((_BYTE *)a2 + 49) & 1) != 0 )
  {
    v34 = *(_BYTE *)(v12 + 1) + v26;
  }
  else
  {
    v33 = 2LL * v26;
    v34 = *(_BYTE *)(v12 + 1) + v33;
  }
  *(_BYTE *)(v12 + 1) = v34;
  return (char *)v16 + v33;
}
