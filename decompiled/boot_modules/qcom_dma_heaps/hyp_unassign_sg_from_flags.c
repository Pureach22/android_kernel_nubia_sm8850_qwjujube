__int64 __fastcall hyp_unassign_sg_from_flags(__int64 a1, __int64 a2, char a3)
{
  __int64 v6; // x0
  int v7; // w22
  __int64 v8; // x20
  unsigned int v9; // w0
  int v10; // w0
  _QWORD *v11; // x0
  unsigned int v12; // w21
  unsigned __int64 v19; // x9
  __int64 result; // x0
  unsigned int v21; // w19
  int v22; // [xsp+0h] [xbp-10h] BYREF
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = _sw_hweight64(a2 & 0x7FFF8000);
  v7 = v6;
  if ( v6 << 32 < 0 || (v8 = _kmalloc_noprof((4 * v6) & 0x3FFFFFFFFLL, 3520)) == 0 )
  {
    result = 4294967284LL;
  }
  else
  {
    v9 = populate_vm_list(a2, v8, (unsigned int)v7);
    if ( v9 )
    {
      v21 = v9;
      printk(&unk_D963, "hyp_unassign_sg_from_flags");
    }
    else
    {
      v22 = 7;
      v23 = 3;
      if ( v7 <= 0 )
      {
        printk(&unk_D985, "hyp_unassign_sg");
        v10 = -22;
      }
      else
      {
        v10 = hyp_assign_table(a1, v8, (unsigned int)v7, &v23, &v22, 1);
        if ( !v10 && (a3 & 1) != 0 )
        {
          if ( *(_DWORD *)(a1 + 8) )
          {
            v11 = *(_QWORD **)a1;
            v12 = 0;
            do
            {
              _X8 = (unsigned __int64 *)(*v11 & 0xFFFFFFFFFFFFFFFCLL);
              __asm { PRFM            #0x11, [X8] }
              do
                v19 = __ldxr(_X8);
              while ( __stxr(v19 & 0xFFFFFFFFFFFF7FFFLL, _X8) );
              ++v12;
              v11 = (_QWORD *)sg_next(v11);
            }
            while ( v12 < *(_DWORD *)(a1 + 8) );
          }
          v10 = 0;
        }
      }
      v21 = v10;
    }
    kfree(v8);
    result = v21;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
