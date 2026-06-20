void __fastcall android_rvh_gh_after_vcpu_run(__int64 a1, unsigned int a2, unsigned int a3, int a4, int *a5)
{
  unsigned __int16 v5; // w22
  unsigned int vm_name; // w0
  __int64 v10; // x22
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  __int64 v19; // x20
  _QWORD *StatusReg; // x23
  __int64 v26; // x8
  int v27; // w8
  _QWORD v29[2]; // [xsp+0h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int16)a2 <= 0x3Fu )
  {
    v5 = a2;
    LODWORD(v29[0]) = 0;
    vm_name = gh_rm_get_vm_name(a2, v29);
    if ( vm_name )
    {
      printk(&unk_7AD3, v5, vm_name);
      goto LABEL_23;
    }
    v10 = gh_vms + 40LL * LODWORD(v29[0]);
    if ( v10 )
    {
      if ( *(_BYTE *)(v10 + 25) == 1 )
      {
        v11 = xa_load(v10 + 8, a3);
        if ( v11 )
        {
          v19 = v11;
          if ( !a4 )
          {
            if ( !*a5 )
            {
              if ( (*(_QWORD *)_ReadStatusReg(SP_EL0) & 2) == 0 )
                goto LABEL_10;
              goto LABEL_9;
            }
            if ( (*a5 & 0xFFFFFFFE) == 4 )
            {
LABEL_9:
              v12 = 0;
              v13 = 0;
              v14 = 0;
              v15 = 0;
              v16 = 0;
              v17 = 0;
              v18 = 0;
              __asm { HVC             #0x6063 }
              v29[0] = 0;
              *(_BYTE *)(v11 + 20) = 1;
            }
          }
LABEL_10:
          StatusReg = (_QWORD *)_ReadStatusReg(SP_EL0);
          v26 = StatusReg[2] - 1LL;
          *((_DWORD *)StatusReg + 4) = v26;
          if ( v26 && StatusReg[2] )
          {
            if ( !a4 )
            {
LABEL_13:
              v27 = *a5;
              if ( *a5 == 256 || v27 == 2 || v27 == 1 && *((_QWORD *)a5 + 2) == 3 )
                _pm_relax(*(_QWORD *)(v19 + 56), v12, v13, v14, v15, v16, v17, v18);
            }
          }
          else
          {
            preempt_schedule();
            if ( !a4 )
              goto LABEL_13;
          }
          if ( ((*StatusReg & 0x40) != 0 || (*StatusReg & 1) != 0) && (*(_BYTE *)(v19 + 20) & 1) == 0 )
          {
            __asm { HVC             #0x6063 }
            v29[0] = 0;
            *(_BYTE *)(v19 + 20) = 1;
          }
        }
      }
    }
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
}
