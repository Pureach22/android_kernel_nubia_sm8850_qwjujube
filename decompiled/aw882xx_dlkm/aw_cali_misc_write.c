__int64 __fastcall aw_cali_misc_write(__int64 a1, int a2, size_t a3)
{
  __int64 v3; // x20
  int v5; // w22
  __int64 *v7; // x9
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v11; // x25
  __int64 v12; // x21
  int v13; // w0
  __int64 *v14; // x8
  __int64 v15; // x1
  void *v16; // x0
  int v17; // w22
  __int64 *v18; // x8
  __int64 v19; // x1
  __int64 *v20; // x8

  v3 = *(_QWORD *)(a1 + 32);
  v5 = a1;
  v7 = *(__int64 **)(v3 + 112);
  v8 = v7[14];
  if ( !v8 )
    v8 = *v7;
  printk(&unk_226CA, v8, "aw_cali_misc_write");
  v9 = _kmalloc_noprof(a3 + 1, 3520);
  if ( !v9 )
    return -12;
  if ( a3 >> 31 )
  {
    v12 = v9;
    __break(0x800u);
    v17 = -14;
    goto LABEL_18;
  }
  v11 = v9;
  _check_object_size(v9, a3, 0);
  v12 = v11;
  if ( inline_copy_from_user(v11, a2, a3) )
  {
    v17 = -14;
  }
  else
  {
    v13 = ((__int64 (__fastcall *)(__int64, __int64))aw_cali_svc_get_cmd_form_str)(v3, v11);
    if ( v13 < 0 )
    {
      v14 = *(__int64 **)(v3 + 112);
      v15 = v14[14];
      if ( !v15 )
        v15 = *v14;
      v16 = &unk_27492;
    }
    else
    {
      if ( v13 <= 3 )
      {
        switch ( v13 )
        {
          case 1:
            v17 = aw_cali_svc_cali_cmd(v3, 2, 0, 3u);
            goto LABEL_18;
          case 2:
            v17 = aw_cali_svc_cali_re(v3, 0, 1);
            goto LABEL_18;
          case 3:
            v17 = aw_cali_svc_cali_f0(v3, 0, 3);
            goto LABEL_18;
        }
      }
      else
      {
        if ( (unsigned int)v13 <= 0x10 )
        {
          if ( ((1 << v13) & 0x1B7E0) != 0 )
          {
            v17 = 0;
            g_msic_wr_flag = v13;
            goto LABEL_18;
          }
          if ( v13 == 11 )
          {
            v17 = aw_cali_misc_switch_dev(v5, v3, (char *)v11);
            goto LABEL_18;
          }
          if ( v13 == 14 )
          {
            v17 = aw_cali_svc_cali_f0_q(v3, 0, 3);
            goto LABEL_18;
          }
        }
        if ( v13 == 4 )
        {
          if ( a3 + 1 < a3 )
          {
            __break(1u);
            return aw_cali_misc_unlocked_ioctl();
          }
          *(_BYTE *)(v11 + a3) = 0;
          v17 = aw_cali_svc_set_devs_re_str(v3, (const char *)(v11 + 9));
          goto LABEL_18;
        }
      }
      v20 = *(__int64 **)(v3 + 112);
      v15 = v20[14];
      if ( !v15 )
        v15 = *v20;
      v16 = &unk_23B53;
    }
    printk(v16, v15, "aw_cali_misc_write");
    v17 = -22;
  }
LABEL_18:
  v18 = *(__int64 **)(v3 + 112);
  v19 = v18[14];
  if ( !v19 )
    v19 = *v18;
  printk(&unk_28219, v19, "aw_cali_misc_write");
  kfree(v12);
  if ( v17 >= 0 )
    return a3;
  else
    return -22;
}
