__int64 __fastcall aw_cali_misc_write_dsp(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x23
  unsigned int v3; // w22
  size_t v5; // x21
  __int64 v6; // x0
  __int64 v7; // x19
  unsigned int v8; // w21
  __int64 *v9; // x8
  __int64 v10; // x1
  __int64 *v11; // x8
  __int64 v12; // x1

  v2 = *(_QWORD *)(a2 + 16);
  v3 = *(_DWORD *)(a2 + 4);
  v5 = *(int *)(a2 + 12);
  v6 = _kmalloc_noprof(v5, 3520);
  v7 = v6;
  if ( !v6 )
    return (unsigned int)-12;
  if ( (v5 & 0x80000000) != 0 )
  {
    __break(0x800u);
    goto LABEL_10;
  }
  _check_object_size(v6, v5, 0);
  if ( inline_copy_from_user(v7, v2, v5) )
  {
LABEL_10:
    v11 = *(__int64 **)(a1 + 112);
    v12 = v11[14];
    if ( !v12 )
      v12 = *v11;
    printk(&unk_226F2, v12, "aw_cali_misc_write_dsp");
    v8 = -14;
    goto LABEL_5;
  }
  v8 = aw882xx_dsp_write_dsp_msg(a1, v3, v7, (unsigned int)v5);
  if ( v8 )
  {
    v9 = *(__int64 **)(a1 + 112);
    v10 = v9[14];
    if ( !v10 )
      v10 = *v9;
    printk(&unk_222B3, v10, "aw_cali_misc_write_dsp");
  }
LABEL_5:
  kfree(v7);
  return v8;
}
