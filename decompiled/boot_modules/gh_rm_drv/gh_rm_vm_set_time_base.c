__int64 __fastcall gh_rm_vm_set_time_base(__int16 a1)
{
  __int64 real_ts64; // x0
  __int64 (__fastcall *v7)(__int64); // x8
  __int64 v8; // x0
  unsigned __int64 v10; // x8
  unsigned int v11; // w0
  __int64 result; // x0
  unsigned int v13; // w19
  __int64 v14; // [xsp+0h] [xbp-40h] BYREF
  __int64 v15; // [xsp+8h] [xbp-38h] BYREF
  __int64 v16; // [xsp+10h] [xbp-30h]
  __int64 v17; // [xsp+18h] [xbp-28h] BYREF
  _WORD v18[2]; // [xsp+24h] [xbp-1Ch] BYREF
  unsigned __int64 v19; // [xsp+28h] [xbp-18h]
  __int64 v20; // [xsp+30h] [xbp-10h]
  __int64 v21; // [xsp+38h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[1] = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v18[0] = a1;
  __asm { MSR             DAIFSet, #3 }
  real_ts64 = ktime_get_real_ts64(&v15);
  v7 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
  if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
    __break(0x8228u);
  v8 = v7(real_ts64);
  __asm { MSR             DAIFClr, #3 }
  if ( v15 <= 0x225C17D03LL )
  {
    if ( v15 >= (__int64)0xFFFFFFFDDA3E82FDLL )
      v10 = v16 + 1000000000 * v15;
    else
      v10 = 0x8000000000000000LL;
  }
  else
  {
    v10 = 0x7FFFFFFFFFFFFFFFLL;
  }
  v19 = v10;
  v20 = v8;
  v11 = gunyah_rm_call(rm, 1442840624, v18, 20, &v14, &v17);
  if ( v11 )
  {
    v13 = v11;
    printk(&unk_13286, "gh_rm_vm_set_time_base");
    result = v13;
  }
  else if ( v17 )
  {
    printk(&unk_134FA, "gh_rm_vm_set_time_base");
    result = 4294967274LL;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
