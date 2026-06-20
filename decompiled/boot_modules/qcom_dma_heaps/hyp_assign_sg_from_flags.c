__int64 __fastcall hyp_assign_sg_from_flags(__int64 a1, int a2, char a3)
{
  __int64 v4; // x28
  __int64 v5; // x24
  __int64 v6; // x0
  __int64 v7; // x22
  unsigned __int64 v8; // x21
  __int64 v9; // x19
  unsigned int v10; // w0
  unsigned __int64 v11; // x26
  unsigned __int64 v12; // x23
  int vmid_perms; // w0
  unsigned int v15; // w22
  _QWORD *v16; // x0
  unsigned int v17; // w21
  unsigned __int64 v23; // x9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v26; // x25
  char v27; // [xsp+0h] [xbp-10h]
  int v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  LOBYTE(v4) = a3;
  LODWORD(v5) = a2;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = _sw_hweight64(a2 & 0x7FFF8000);
  v7 = v6;
  if ( v6 << 32 < 0 )
    goto LABEL_24;
  v8 = (4 * v6) & 0x3FFFFFFFFLL;
  v9 = _kmalloc_noprof(v8, 3520);
LABEL_3:
  if ( !v9 )
  {
LABEL_24:
    result = 4294967284LL;
  }
  else
  {
    v10 = populate_vm_list(v5, v9, v7);
    if ( v10 )
    {
      v15 = v10;
      printk(&unk_D89C, "hyp_assign_sg_from_flags");
    }
    else
    {
      v28 = 3;
      if ( (int)v7 <= 0 )
      {
        printk(&unk_E2E6, "hyp_assign_sg");
        v15 = -22;
      }
      else
      {
        v5 = _kmalloc_noprof(4 * (v7 & 0x7FFFFFFF), 3520);
        if ( v5 )
        {
          v27 = v4;
          v4 = 4 * (v7 & 0x7FFFFFFF);
          v11 = 0;
          v12 = v8;
          do
          {
            if ( (v11 & 0x8000000000000000LL) != 0
              || v8 < v11
              || (_CF = v12 >= 4, v12 -= 4LL, !_CF)
              || (vmid_perms = msm_secure_get_vmid_perms(*(unsigned int *)(v9 + v11)), 4 * (v7 & 0x7FFFFFFF) == v11)
              || 4 * (unsigned __int64)(v7 & 0x7FFFFFFF) <= v11 )
            {
              __break(1u);
              StatusReg = _ReadStatusReg(SP_EL0);
              v26 = *(_QWORD *)(StatusReg + 80);
              *(_QWORD *)(StatusReg + 80) = &hyp_assign_sg_from_flags__alloc_tag;
              if ( v7 << 32 < 0 )
              {
                v8 = 0;
                v9 = 0;
              }
              else
              {
                v8 = (4 * v7) & 0x3FFFFFFFFLL;
                v9 = _kmalloc_noprof(v8, 3520);
              }
              *(_QWORD *)(StatusReg + 80) = v26;
              goto LABEL_3;
            }
            *(_DWORD *)(v5 + v11) = vmid_perms;
            v11 += 4LL;
          }
          while ( v4 != v11 );
          v15 = hyp_assign_table(a1, &v28, 1, v9, v5, (unsigned int)v7);
          if ( v15 )
          {
            printk(&unk_E32C, "hyp_assign_sg");
          }
          else if ( (v27 & 1) != 0 && *(_DWORD *)(a1 + 8) )
          {
            v16 = *(_QWORD **)a1;
            v17 = 0;
            do
            {
              _X8 = (unsigned __int64 *)(*v16 & 0xFFFFFFFFFFFFFFFCLL);
              __asm { PRFM            #0x11, [X8] }
              do
                v23 = __ldxr(_X8);
              while ( __stxr(v23 | 0x8000, _X8) );
              ++v17;
              v16 = (_QWORD *)sg_next(v16);
            }
            while ( v17 < *(_DWORD *)(a1 + 8) );
          }
          kfree(v5);
        }
        else
        {
          v15 = -12;
        }
      }
    }
    kfree(v9);
    result = v15;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
