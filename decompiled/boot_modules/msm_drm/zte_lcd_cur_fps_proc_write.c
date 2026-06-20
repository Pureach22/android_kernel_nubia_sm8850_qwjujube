__int64 __fastcall zte_lcd_cur_fps_proc_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  size_t v3; // x19
  size_t v6; // x21
  unsigned __int8 *v7; // x20
  unsigned __int64 StatusReg; // x24
  __int64 v9; // x25

  v3 = a3;
  v6 = a3 + 1;
  v7 = (unsigned __int8 *)_kmalloc_noprof(a3 + 1, 3520);
  if ( !v7 )
    return -12;
  while ( 1 )
  {
    if ( v3 >> 31 )
    {
      __break(0x800u);
LABEL_4:
      kfree(v7);
      return -14;
    }
    a1 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
    _check_object_size(v7, v3, 0);
    if ( inline_copy_from_user_8((__int64)v7, a2, v3) )
      goto LABEL_4;
    if ( !a1 )
      break;
    if ( v6 )
    {
      zte_set_disp_parameter(a1, 2, *v7 - 48);
      kfree(v7);
      return v3;
    }
    __break(1u);
    v6 = v3 + 1;
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &zte_lcd_cur_fps_proc_write__alloc_tag;
    v7 = (unsigned __int8 *)_kmalloc_noprof(v3 + 1, 3520);
    *(_QWORD *)(StatusReg + 80) = v9;
    if ( !v7 )
      return -12;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: MSM_LCD no primary display device\n");
  return -19;
}
