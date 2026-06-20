__int64 *__fastcall dp_rx_sg_create(__int64 a1, __int64 *a2)
{
  int v4; // w27
  __int64 *v5; // x8
  int v6; // w8
  unsigned int v7; // w9
  unsigned int v8; // w21
  unsigned int v9; // w8
  __int64 *v10; // x9
  int v11; // w24
  int v12; // w9
  __int64 v13; // x0
  _DWORD *v14; // x8
  unsigned __int16 v15; // w0
  int v16; // w22
  unsigned int v17; // w9
  int v18; // w28
  unsigned int v19; // w23
  unsigned __int16 v20; // w21
  unsigned int v21; // w8
  unsigned int v22; // w8
  int v23; // w9
  int v24; // w9
  int v25; // w9
  int v26; // w10
  __int64 v27; // x8
  __int64 v28; // x1
  __int64 v29; // x8
  int v30; // w9
  int v31; // w10
  __int16 v32; // w8
  __int64 *v33; // x21
  int v34; // w26
  unsigned __int16 v35; // w23
  unsigned __int16 v36; // w0
  int v37; // w25
  unsigned int v38; // w28
  unsigned int v39; // w9
  unsigned int v40; // w27
  unsigned __int16 v41; // w22
  unsigned int v42; // w8
  unsigned int v43; // w8
  int v44; // w9
  int v45; // w9
  int v46; // w9
  int v47; // w10
  int v48; // w9
  int v49; // w10
  __int64 v50; // x8
  __int64 v51; // x1
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w8
  __int64 v61; // x0
  char v62; // w8
  __int64 *v63; // x9
  int v64; // w8
  int v65; // w11
  int v66; // w9
  int v67; // w10
  __int64 v68; // x8
  __int64 *v70; // [xsp+8h] [xbp-18h]
  _QWORD v71[2]; // [xsp+10h] [xbp-10h] BYREF

  v71[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((unsigned __int16 *)a2 + 30);
  if ( !*((_WORD *)a2 + 30) && a2 )
  {
    v5 = a2;
    while ( (*((_BYTE *)v5 + 84) & 2) != 0 )
    {
      v5 = (__int64 *)*v5;
      if ( !v5 )
        goto LABEL_8;
    }
    *((_WORD *)a2 + 30) = *((_WORD *)v5 + 30);
  }
LABEL_8:
  v6 = *((unsigned __int8 *)a2 + 84);
  if ( (~v6 & 5) == 0 )
  {
    v7 = *((_DWORD *)a2 + 28);
    v8 = *(unsigned __int16 *)(a1 + 1138) + v4;
    v9 = v8 - v7;
    if ( v8 < v7 )
    {
      skb_trim(a2, v8);
      goto LABEL_38;
    }
    if ( *((_DWORD *)a2 + 29) )
    {
      v9 = v8 - v7;
      if ( v8 != v7 )
      {
        v12 = 0;
        goto LABEL_35;
      }
    }
    else
    {
      v26 = *((_DWORD *)a2 + 52);
      v25 = *((_DWORD *)a2 + 53);
      if ( v25 - v26 < v9 )
      {
        v12 = v26 - v25;
LABEL_35:
        if ( (unsigned int)pskb_expand_head(a2, 0, v12 + v9, 2080) )
          dev_kfree_skb_any_reason(a2, 1);
      }
    }
    skb_put(a2, v8 - *((_DWORD *)a2 + 28));
LABEL_38:
    v27 = a2[5];
    v28 = *(unsigned __int16 *)(a1 + 1138);
    if ( v27 )
    {
      v29 = v27 + v28;
LABEL_88:
      a2[5] = v29;
      goto LABEL_89;
    }
    goto LABEL_89;
  }
  if ( a2 )
  {
    v10 = a2;
    v71[0] = 0;
    while ( (*((_BYTE *)v10 + 84) & 2) != 0 )
    {
      v10 = (__int64 *)*v10;
      if ( !v10 )
        goto LABEL_15;
    }
    v13 = v10[28];
    v14 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 880LL);
    if ( *(v14 - 1) != -177782713 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *))v14)(v13, v71);
    v11 = LOWORD(v71[0]);
    LOBYTE(v6) = *((_BYTE *)a2 + 84);
  }
  else
  {
LABEL_15:
    v11 = 0;
  }
  *((_BYTE *)a2 + 84) = v6 | 1;
  v70 = (__int64 *)*a2;
  v15 = wlan_cfg_rx_buffer_size(*(_QWORD *)(a1 + 40));
  v16 = v15;
  v17 = *((_DWORD *)a2 + 28);
  v18 = v11 + *(unsigned __int16 *)(a1 + 1138);
  v19 = v18 + v4;
  if ( v18 + v4 > (unsigned int)v15 )
  {
    v20 = v15;
    v21 = v15 - v17;
    if ( v15 < v17 )
    {
      skb_trim(a2, v15);
LABEL_45:
      v32 = v18 - v20;
      v33 = v70;
      v34 = 0;
      v35 = v4 + v32;
      while ( 1 )
      {
        v36 = wlan_cfg_rx_buffer_size(*(_QWORD *)(a1 + 40));
        v37 = *(unsigned __int16 *)(a1 + 1138);
        v38 = v36;
        v39 = *((_DWORD *)v33 + 28);
        v40 = v37 + v35;
        if ( v40 > v36 )
        {
          v41 = v36;
          v42 = v36 - v39;
          if ( v36 < v39 )
          {
            skb_trim(v33, v36);
LABEL_63:
            v35 = v35 - v41 + v37;
            goto LABEL_70;
          }
          if ( *((_DWORD *)v33 + 29) )
          {
            v42 = v36 - v39;
            if ( v36 != v39 )
            {
              v44 = 0;
LABEL_60:
              if ( (unsigned int)pskb_expand_head(v33, 0, v44 + v42, 2080) )
                dev_kfree_skb_any_reason(v33, 1);
            }
          }
          else
          {
            v47 = *((_DWORD *)v33 + 52);
            v46 = *((_DWORD *)v33 + 53);
            if ( v46 - v47 < v42 )
            {
              v44 = v47 - v46;
              goto LABEL_60;
            }
          }
          skb_put(v33, v38 - *((_DWORD *)v33 + 28));
          goto LABEL_63;
        }
        v43 = v40 - v39;
        if ( v40 >= v39 )
          break;
        skb_trim(v33, v40);
LABEL_69:
        v35 = 0;
LABEL_70:
        v50 = v33[5];
        v51 = *(unsigned __int16 *)(a1 + 1138);
        if ( v50 )
          v33[5] = v50 + v51;
        skb_pull(v33, v51);
        if ( (*((_BYTE *)v33 + 68) & 4) != 0 )
          v60 = *((unsigned __int16 *)v33 + 33);
        else
          v60 = 0;
        v34 += v60 + *((_DWORD *)v33 + 28);
        if ( v40 <= v38 )
        {
          v62 = *((_BYTE *)v33 + 84);
          v63 = (__int64 *)*v33;
          *v33 = 0;
          *((_BYTE *)v33 + 84) = v62 & 0xFE;
          *(_QWORD *)(a2[27] + *((unsigned int *)a2 + 53) + 8) = v70;
          v65 = *((_DWORD *)a2 + 28);
          v64 = *((_DWORD *)a2 + 29);
          *a2 = (__int64)v63;
          *((_DWORD *)a2 + 28) = v65 + (unsigned __int16)v34;
          *((_DWORD *)a2 + 29) = v64 + (unsigned __int16)v34;
          goto LABEL_86;
        }
        if ( (*((_BYTE *)v33 + 84) & 4) != 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Invalid packet length",
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            "dp_rx_sg_create");
          v61 = printk(
                  &unk_AAA255,
                  "0",
                  "dp_rx_sg_create",
                  "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx.c");
          dump_stack(v61);
        }
        v33 = (__int64 *)*v33;
      }
      if ( *((_DWORD *)v33 + 29) )
      {
        v43 = v40 - v39;
        if ( v40 != v39 )
        {
          v45 = 0;
          goto LABEL_66;
        }
      }
      else
      {
        v49 = *((_DWORD *)v33 + 52);
        v48 = *((_DWORD *)v33 + 53);
        if ( v48 - v49 < v43 )
        {
          v45 = v49 - v48;
LABEL_66:
          if ( (unsigned int)pskb_expand_head(v33, 0, v45 + v43, 2080) )
            dev_kfree_skb_any_reason(v33, 1);
        }
      }
      skb_put(v33, v40 - *((_DWORD *)v33 + 28));
      goto LABEL_69;
    }
    if ( *((_DWORD *)a2 + 29) )
    {
      v21 = v15 - v17;
      if ( v15 != v17 )
      {
        v23 = 0;
        goto LABEL_42;
      }
    }
    else
    {
      v31 = *((_DWORD *)a2 + 52);
      v30 = *((_DWORD *)a2 + 53);
      if ( v30 - v31 < v21 )
      {
        v23 = v31 - v30;
LABEL_42:
        if ( (unsigned int)pskb_expand_head(a2, 0, v23 + v21, 2080) )
          dev_kfree_skb_any_reason(a2, 1);
      }
    }
    skb_put(a2, (unsigned int)(v16 - *((_DWORD *)a2 + 28)));
    goto LABEL_45;
  }
  v22 = v19 - v17;
  if ( v19 < v17 )
  {
    skb_trim(a2, v19);
    goto LABEL_84;
  }
  if ( *((_DWORD *)a2 + 29) )
  {
    v22 = v19 - v17;
    if ( v19 != v17 )
    {
      v24 = 0;
      goto LABEL_81;
    }
  }
  else
  {
    v67 = *((_DWORD *)a2 + 52);
    v66 = *((_DWORD *)a2 + 53);
    if ( v66 - v67 < v22 )
    {
      v24 = v67 - v66;
LABEL_81:
      if ( (unsigned int)pskb_expand_head(a2, 0, v24 + v22, 2080) )
        dev_kfree_skb_any_reason(a2, 1);
    }
  }
  skb_put(a2, v19 - *((_DWORD *)a2 + 28));
LABEL_84:
  if ( a1 )
    ++*(_DWORD *)(a1 + 14172);
LABEL_86:
  v68 = a2[5];
  v28 = v11 + (unsigned int)*(unsigned __int16 *)(a1 + 1138);
  if ( v68 )
  {
    v29 = v68 + (unsigned int)v28;
    goto LABEL_88;
  }
LABEL_89:
  skb_pull(a2, v28);
  _ReadStatusReg(SP_EL0);
  return a2;
}
