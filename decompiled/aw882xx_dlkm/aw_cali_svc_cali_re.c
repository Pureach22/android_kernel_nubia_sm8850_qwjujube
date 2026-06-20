__int64 __fastcall aw_cali_svc_cali_re(__int64 a1, char a2, char a3)
{
  __int64 *v5; // x8
  __int64 v6; // x1
  __int64 *v7; // x8
  __int64 v8; // x1
  unsigned int list_head; // w0
  _QWORD *v10; // x28
  _QWORD *v11; // x20
  __int64 *v12; // x8
  __int64 v13; // x1
  __int64 *v14; // x8
  __int64 v15; // x1
  __int64 *v16; // x8
  __int64 v17; // x1
  __int64 result; // x0
  _QWORD *v19; // x21
  _QWORD *v20; // x20
  __int64 *v21; // x8
  __int64 v22; // x1
  __int64 *v23; // x8
  __int64 v24; // x1
  unsigned int v25; // w0
  unsigned int v26; // w22
  unsigned int re; // w0
  __int64 *v28; // x8
  __int64 v29; // x1
  _QWORD *v30; // x24
  _QWORD *v31; // x25
  unsigned int v32; // w26
  __int64 *v33; // x8
  __int64 v34; // x1
  __int64 *v35; // x8
  unsigned int v36; // w19
  __int64 v37; // x1
  unsigned int v38; // w21
  __int64 *v39; // x8
  __int64 v40; // x1
  _QWORD v41[2]; // [xsp+0h] [xbp-10h] BYREF

  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
  {
    if ( *(_BYTE *)(a1 + 665) )
    {
      aw882xx_dev_mute(a1, 0);
    }
    else
    {
      v5 = *(__int64 **)(a1 + 112);
      v6 = v5[14];
      if ( !v6 )
        v6 = *v5;
      printk(&unk_23537, v6, "aw_cali_svc_run_mute");
    }
    v21 = *(__int64 **)(a1 + 112);
    v22 = v21[14];
    if ( !v22 )
      v22 = *v21;
    printk(&unk_22D82, v22, "aw_cali_svc_run_mute");
    aw882xx_dev_iv_forbidden_output(a1);
    v23 = *(__int64 **)(a1 + 112);
    g_cali_status = 1;
    v24 = v23[14];
    if ( !v24 )
      v24 = *v23;
    printk(&unk_261EB, v24, "aw_cali_svc_set_cali_status");
    if ( (a3 & 1) != 0 && (v25 = aw882xx_dsp_hmute_en(a1, 1), (v25 & 0x80000000) != 0) )
    {
      v26 = v25;
      aw882xx_dsp_cali_en(a1, 0);
    }
    else
    {
      re = aw882xx_dsp_cali_en(a1, 1);
      if ( (re & 0x80000000) == 0 )
      {
        msleep((unsigned int)g_cali_re_time);
        re = aw_cali_svc_dev_get_re(a1);
      }
      v26 = re;
      aw882xx_dsp_cali_en(a1, 0);
      if ( (a3 & 1) == 0 )
        goto LABEL_39;
    }
    aw882xx_dsp_hmute_en(a1, 0);
LABEL_39:
    v28 = *(__int64 **)(a1 + 112);
    g_cali_status = 0;
    v29 = v28[14];
    if ( !v29 )
      v29 = *v28;
    printk(&unk_261EB, v29, "aw_cali_svc_set_cali_status");
    aw882xx_dev_iv_forbidden_output(a1);
    result = v26;
    goto LABEL_51;
  }
  v7 = *(__int64 **)(a1 + 112);
  v41[0] = 0;
  v8 = v7[14];
  if ( !v8 )
    v8 = *v7;
  printk(&unk_26EB3, v8, "aw_cali_svc_devs_cali_re");
  list_head = aw882xx_dev_get_list_head(v41);
  if ( list_head )
  {
    v35 = *(__int64 **)(a1 + 112);
    v36 = list_head;
    v37 = v35[14];
    if ( !v37 )
      v37 = *v35;
    printk(&unk_24B82, v37, "aw_cali_svc_devs_cali_re");
    result = v36;
  }
  else
  {
    v10 = (_QWORD *)v41[0];
    v11 = *(_QWORD **)v41[0];
    if ( *(_QWORD *)v41[0] == v41[0] )
    {
LABEL_23:
      msleep((unsigned int)g_cali_re_time);
      v19 = (_QWORD *)v41[0];
      v20 = *(_QWORD **)v41[0];
      if ( *(_QWORD *)v41[0] == v41[0] )
      {
        result = 0xFFFFFFFFLL;
      }
      else
      {
        while ( 1 )
        {
          result = aw_cali_svc_dev_get_re(v20 - 153);
          if ( (result & 0x80000000) != 0 )
            break;
          v20 = (_QWORD *)*v20;
          if ( v20 == v19 )
            goto LABEL_43;
        }
        v38 = result;
        v39 = (__int64 *)*(v20 - 139);
        v40 = v39[14];
        if ( !v40 )
          v40 = *v39;
        printk(&unk_251C8, v40, "aw_cali_svc_devs_get_cali_cali_data");
        result = v38;
      }
    }
    else
    {
      while ( 1 )
      {
        if ( *((_BYTE *)v11 - 559) )
        {
          aw882xx_dev_mute(v11 - 153, 0);
        }
        else
        {
          v12 = (__int64 *)*(v11 - 139);
          v13 = v12[14];
          if ( !v13 )
            v13 = *v12;
          printk(&unk_23537, v13, "aw_cali_svc_run_mute");
        }
        v14 = (__int64 *)*(v11 - 139);
        v15 = v14[14];
        if ( !v15 )
          v15 = *v14;
        printk(&unk_22D82, v15, "aw_cali_svc_run_mute");
        aw882xx_dev_iv_forbidden_output(v11 - 153);
        v16 = (__int64 *)*(v11 - 139);
        g_cali_status = 1;
        v17 = v16[14];
        if ( !v17 )
          v17 = *v16;
        printk(&unk_261EB, v17, "aw_cali_svc_set_cali_status");
        if ( (a3 & 1) != 0 )
        {
          result = aw882xx_dsp_hmute_en(v11 - 153, 1);
          if ( (result & 0x80000000) != 0 )
            break;
        }
        result = aw882xx_dsp_cali_en(v11 - 153, 1);
        if ( (result & 0x80000000) != 0 )
          break;
        v11 = (_QWORD *)*v11;
        if ( v11 == v10 )
          goto LABEL_23;
      }
    }
LABEL_43:
    v30 = (_QWORD *)v41[0];
    v31 = *(_QWORD **)v41[0];
    if ( *(_QWORD *)v41[0] != v41[0] )
    {
      v32 = result;
      do
      {
        aw882xx_dsp_cali_en(v31 - 153, 0);
        if ( (a3 & 1) != 0 )
          aw882xx_dsp_hmute_en(v31 - 153, 0);
        v33 = (__int64 *)*(v31 - 139);
        g_cali_status = 0;
        v34 = v33[14];
        if ( !v34 )
          v34 = *v33;
        printk(&unk_261EB, v34, "aw_cali_svc_set_cali_status");
        aw882xx_dev_iv_forbidden_output(v31 - 153);
        v31 = (_QWORD *)*v31;
      }
      while ( v31 != v30 );
      result = v32;
    }
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
