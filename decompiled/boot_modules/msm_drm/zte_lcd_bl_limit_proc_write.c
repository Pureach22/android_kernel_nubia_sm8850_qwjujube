size_t __fastcall zte_lcd_bl_limit_proc_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  size_t v3; // x19
  __int64 v6; // x0
  const char *v7; // x20
  __int64 v8; // x22
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = _kmalloc_noprof(a3 + 1, 3520);
  v7 = (const char *)v6;
  v10 = 0;
  if ( !v6 )
  {
    v3 = -12;
    goto LABEL_10;
  }
  if ( v3 >> 31 )
  {
    __break(0x800u);
    goto LABEL_4;
  }
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
  _check_object_size(v6, v3, 0);
  if ( inline_copy_from_user_8((__int64)v7, a2, v3) )
  {
LABEL_4:
    kfree(v7);
    v3 = -14;
    goto LABEL_10;
  }
  sscanf(v7, "%d", &v10);
  if ( v8 )
  {
    zte_set_disp_parameter(v8, 6, v10);
    kfree(v7);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: MSM_LCD no primary display device\n");
    v3 = -19;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v3;
}
