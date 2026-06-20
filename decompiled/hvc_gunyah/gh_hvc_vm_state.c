__int64 __fastcall gh_hvc_vm_state(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 v4; // x0
  unsigned __int64 *v6; // x19
  unsigned __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // x3
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a3;
  v10 = 0;
  if ( (unsigned int)gh_rm_get_vm_name(v4, &v10) )
    goto LABEL_2;
  if ( a2 != 1 )
  {
    if ( a2 != 5 )
      goto LABEL_2;
    if ( v10 < 5 )
    {
      if ( !gh_hvc_data[268 * v10] )
        goto LABEL_2;
      hvc_remove();
      if ( v10 <= 4 )
      {
        gh_hvc_data[268 * v10] = 0;
        goto LABEL_2;
      }
    }
LABEL_13:
    __break(0x5512u);
    JUMPOUT(0x6820);
  }
  if ( v10 > 4 )
    goto LABEL_13;
  v6 = &gh_hvc_data[268 * v10];
  if ( !*v6 )
  {
    v7 = hvc_alloc(v10 | 0x474E5948, v10, gh_hv_ops, 256);
    *v6 = v7;
    if ( v7 >= 0xFFFFFFFFFFFFF001LL )
    {
      *v6 = 0;
      printk(&unk_96E7, v7, v8, v9);
    }
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return 0;
}
