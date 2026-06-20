__int64 __fastcall aw_cali_svc_cali_f0(__int64 a1, char a2, char a3)
{
  unsigned int list_head; // w0
  _QWORD *v6; // x28
  _QWORD *v7; // x20
  __int64 *v8; // x8
  __int64 v9; // x1
  __int64 *v10; // x8
  __int64 v11; // x1
  __int64 *v12; // x8
  __int64 v13; // x1
  __int64 result; // x0
  _QWORD *v15; // x21
  _QWORD *v16; // x20
  _QWORD *v17; // x24
  _QWORD *v18; // x25
  unsigned int v19; // w26
  __int64 *v20; // x8
  __int64 v21; // x1
  __int64 *v22; // x8
  __int64 v23; // x1
  __int64 *v24; // x8
  unsigned int v25; // w19
  __int64 v26; // x1
  unsigned int v27; // w21
  __int64 *v28; // x8
  __int64 v29; // x1
  __int64 *v30; // x8
  __int64 v31; // x1
  __int64 *v32; // x8
  __int64 v33; // x1
  unsigned int v34; // w0
  unsigned int v35; // w22
  unsigned int f0; // w0
  __int64 *v37; // x8
  __int64 v38; // x1
  _QWORD v39[2]; // [xsp+0h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
  {
    if ( *(_BYTE *)(a1 + 665) )
    {
      aw882xx_dev_mute(a1, 0);
    }
    else
    {
      v22 = *(__int64 **)(a1 + 112);
      v23 = v22[14];
      if ( !v23 )
        v23 = *v22;
      printk(&unk_23537, v23, "aw_cali_svc_run_mute");
    }
    v30 = *(__int64 **)(a1 + 112);
    v31 = v30[14];
    if ( !v31 )
      v31 = *v30;
    printk(&unk_22D82, v31, "aw_cali_svc_run_mute");
    aw882xx_dev_iv_forbidden_output(a1);
    v32 = *(__int64 **)(a1 + 112);
    g_cali_status = 1;
    v33 = v32[14];
    if ( !v33 )
      v33 = *v32;
    printk(&unk_261EB, v33, "aw_cali_svc_set_cali_status");
    if ( (a3 & 2) != 0 && (v34 = aw882xx_dsp_noise_en(a1, 1), (v34 & 0x80000000) != 0) )
    {
      v35 = v34;
      aw882xx_dsp_cali_en(a1, 0);
    }
    else
    {
      f0 = aw882xx_dsp_cali_en(a1, 2);
      if ( (f0 & 0x80000000) == 0 )
      {
        msleep(5000);
        f0 = aw_cali_svc_dev_get_f0(a1);
      }
      v35 = f0;
      aw882xx_dsp_cali_en(a1, 0);
      if ( (a3 & 2) == 0 )
        goto LABEL_53;
    }
    aw882xx_dsp_noise_en(a1, 0);
LABEL_53:
    v37 = *(__int64 **)(a1 + 112);
    g_cali_status = 0;
    v38 = v37[14];
    if ( !v38 )
      v38 = *v37;
    printk(&unk_261EB, v38, "aw_cali_svc_set_cali_status");
    aw882xx_dev_iv_forbidden_output(a1);
    aw_cali_svc_run_mute(a1, *(_BYTE *)(a1 + 664));
    result = v35;
    goto LABEL_30;
  }
  v39[0] = 0;
  list_head = aw882xx_dev_get_list_head(v39);
  if ( list_head )
  {
    v24 = *(__int64 **)(a1 + 112);
    v25 = list_head;
    v26 = v24[14];
    if ( !v26 )
      v26 = *v24;
    printk(&unk_24B82, v26, "aw_cali_svc_devs_cali_f0");
    result = v25;
  }
  else
  {
    v6 = (_QWORD *)v39[0];
    v7 = *(_QWORD **)v39[0];
    if ( *(_QWORD *)v39[0] == v39[0] )
    {
LABEL_17:
      msleep(5000);
      v15 = (_QWORD *)v39[0];
      v16 = *(_QWORD **)v39[0];
      if ( *(_QWORD *)v39[0] == v39[0] )
      {
        result = 0xFFFFFFFFLL;
      }
      else
      {
        while ( 1 )
        {
          result = aw_cali_svc_dev_get_f0(v16 - 153);
          if ( (result & 0x80000000) != 0 )
            break;
          v16 = (_QWORD *)*v16;
          if ( v16 == v15 )
            goto LABEL_22;
        }
        v27 = result;
        v28 = (__int64 *)*(v16 - 139);
        v29 = v28[14];
        if ( !v29 )
          v29 = *v28;
        printk(&unk_251C8, v29, "aw_cali_svc_devs_get_cali_cali_data");
        result = v27;
      }
    }
    else
    {
      while ( 1 )
      {
        if ( *((_BYTE *)v7 - 559) )
        {
          aw882xx_dev_mute(v7 - 153, 0);
        }
        else
        {
          v8 = (__int64 *)*(v7 - 139);
          v9 = v8[14];
          if ( !v9 )
            v9 = *v8;
          printk(&unk_23537, v9, "aw_cali_svc_run_mute");
        }
        v10 = (__int64 *)*(v7 - 139);
        v11 = v10[14];
        if ( !v11 )
          v11 = *v10;
        printk(&unk_22D82, v11, "aw_cali_svc_run_mute");
        aw882xx_dev_iv_forbidden_output(v7 - 153);
        v12 = (__int64 *)*(v7 - 139);
        g_cali_status = 1;
        v13 = v12[14];
        if ( !v13 )
          v13 = *v12;
        printk(&unk_261EB, v13, "aw_cali_svc_set_cali_status");
        if ( (a3 & 2) != 0 )
        {
          result = aw882xx_dsp_noise_en(v7 - 153, 1);
          if ( (result & 0x80000000) != 0 )
            break;
        }
        result = aw882xx_dsp_cali_en(v7 - 153, 2);
        if ( (result & 0x80000000) != 0 )
          break;
        v7 = (_QWORD *)*v7;
        if ( v7 == v6 )
          goto LABEL_17;
      }
    }
LABEL_22:
    v17 = (_QWORD *)v39[0];
    v18 = *(_QWORD **)v39[0];
    if ( *(_QWORD *)v39[0] != v39[0] )
    {
      v19 = result;
      do
      {
        aw882xx_dsp_cali_en(v18 - 153, 0);
        if ( (a3 & 2) != 0 )
          aw882xx_dsp_noise_en(v18 - 153, 0);
        v20 = (__int64 *)*(v18 - 139);
        g_cali_status = 0;
        v21 = v20[14];
        if ( !v21 )
          v21 = *v20;
        printk(&unk_261EB, v21, "aw_cali_svc_set_cali_status");
        aw882xx_dev_iv_forbidden_output(v18 - 153);
        aw_cali_svc_run_mute((__int64)(v18 - 153), *((_BYTE *)v18 - 560));
        v18 = (_QWORD *)*v18;
      }
      while ( v18 != v17 );
      result = v19;
    }
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
