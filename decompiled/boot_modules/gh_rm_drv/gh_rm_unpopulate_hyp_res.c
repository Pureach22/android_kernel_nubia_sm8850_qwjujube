__int64 __fastcall gh_rm_unpopulate_hyp_res(__int64 a1)
{
  unsigned int v1; // w20
  unsigned __int64 hyp_res; // x0
  unsigned __int64 v3; // x19
  unsigned __int64 v4; // x22
  unsigned int v5; // w21
  unsigned __int64 v6; // x23
  unsigned int v7; // w2
  __int64 v8; // x1
  unsigned int v9; // w0
  __int64 (__fastcall *v10)(_QWORD, int *); // x8
  void *v11; // x9
  __int64 v12; // x1
  __int64 (__fastcall *v13)(_QWORD, __int64, __int64, int *); // x9
  __int64 v14; // x2
  void *v15; // x8
  int v17; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v1 = a1;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = -1;
  v18 = 0;
  hyp_res = gh_rm_vm_get_hyp_res(a1, &v18);
  v3 = hyp_res;
  if ( hyp_res && hyp_res <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( v18 )
    {
      v4 = 0;
      v5 = 0;
      v6 = hyp_res + 12;
      while ( 1 )
      {
        v7 = *(unsigned __int8 *)(v6 - 12);
        if ( (v7 & 0xFE) == 2 )
        {
          v8 = *(unsigned int *)(v6 - 4);
          if ( (unsigned int)v8 < 0x101 )
            goto LABEL_5;
        }
        else
        {
          v8 = *(unsigned int *)(v6 - 4);
          if ( v7 <= 1 && (unsigned int)v8 < 0x100 )
            goto LABEL_5;
        }
        if ( *(unsigned __int8 *)(v6 - 12) <= 3u )
          break;
        if ( *(unsigned __int8 *)(v6 - 12) > 5u )
        {
          if ( v7 == 6 )
            goto LABEL_34;
          if ( v7 != 8 )
          {
            printk(&unk_12696, "gh_rm_unpopulate_hyp_res");
            v5 = -22;
            goto LABEL_44;
          }
          v11 = gh_wdog_manage_fn;
          if ( !gh_wdog_manage_fn )
            goto LABEL_34;
          v12 = *(_QWORD *)v6;
          if ( *((_DWORD *)gh_wdog_manage_fn - 1) != -1132193203 )
            __break(0x8229u);
          v9 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD))v11)(v1, v12, 0);
          goto LABEL_33;
        }
        if ( v7 == 4 )
        {
          v13 = (__int64 (__fastcall *)(_QWORD, __int64, __int64, int *))gh_vcpu_affinity_reset_fn;
          if ( gh_vcpu_affinity_reset_fn )
          {
            v14 = *(_QWORD *)v6;
            if ( *((_DWORD *)gh_vcpu_affinity_reset_fn - 1) != 1949169083 )
              __break(0x8229u);
            v9 = v13(v1, v8, v14, &v17);
            goto LABEL_33;
          }
        }
        else
        {
          v10 = (__int64 (__fastcall *)(_QWORD, int *))gh_vpm_grp_reset_fn;
          if ( gh_vpm_grp_reset_fn )
          {
            if ( *((_DWORD *)gh_vpm_grp_reset_fn - 1) != 699811233 )
              __break(0x8228u);
            v9 = v10(v1, &v17);
            goto LABEL_33;
          }
        }
LABEL_34:
        if ( (v5 & 0x80000000) != 0 )
          goto LABEL_44;
        if ( (v17 & 0x80000000) == 0 && !(unsigned int)gh_put_irq() )
          gh_rm_vm_irq_release(*(unsigned int *)(v6 + 8));
LABEL_5:
        ++v4;
        v6 += 44LL;
        if ( v4 >= v18 )
          goto LABEL_40;
      }
      if ( *(unsigned __int8 *)(v6 - 12) > 1u )
      {
        v9 = gh_msgq_reset_cap_info((unsigned int)v8, v7 != 2, &v17);
      }
      else if ( *(_BYTE *)(v6 - 12) )
      {
        v9 = gh_dbl_reset_cap_info((unsigned int)v8, 1, &v17);
      }
      else
      {
        v9 = gh_dbl_reset_cap_info((unsigned int)v8, 0, &v17);
      }
LABEL_33:
      v5 = v9;
      goto LABEL_34;
    }
    v5 = 0;
LABEL_40:
    v15 = gh_all_res_populated_fn;
    if ( gh_all_res_populated_fn )
    {
      if ( *((_DWORD *)gh_all_res_populated_fn - 1) != -1620602384 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD, _QWORD))v15)(v1, 0);
    }
LABEL_44:
    kfree(v3);
  }
  else
  {
    v5 = hyp_res;
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
