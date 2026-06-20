__int64 __fastcall swrm_bulk_write(__int64 a1, unsigned __int8 a2, __int64 a3, __int64 a4, unsigned __int64 a5)
{
  __int64 v6; // x19
  int v11; // w21
  unsigned __int64 v12; // x21
  __int64 v13; // x20
  unsigned __int64 v14; // x22
  __int64 v15; // x0
  __int64 v16; // x23
  unsigned __int64 v17; // x8
  int v18; // w11
  unsigned int v19; // w15
  int v20; // w13
  int v21; // w14
  int v22; // w15
  int v23; // w16
  unsigned __int64 v24; // x16
  unsigned int v25; // w21
  unsigned __int64 StatusReg; // x22
  __int64 v28; // x23
  __int64 v29; // x0
  __int64 v30; // x19

  if ( !a1 || (v6 = *(_QWORD *)(a1 + 152)) == 0 || !*(_QWORD *)(v6 + 9064) )
  {
    if ( (unsigned int)__ratelimit(&swrm_bulk_write__rs, "swrm_bulk_write") )
      dev_err(a1, "%s: swrm is NULL\n", "swrm_bulk_write");
    return 4294967274LL;
  }
  if ( !a5 )
    return 4294967274LL;
  mutex_lock(v6 + 8736);
  v11 = *(unsigned __int8 *)(v6 + 15748);
  mutex_unlock(v6 + 8736);
  if ( v11 != 1 )
    return 0;
  _pm_runtime_resume(*(_QWORD *)(v6 + 8512), 4);
  if ( a2 )
  {
    if ( !(a5 >> 62) )
    {
      v12 = 4 * a5;
      v13 = _kmalloc_noprof(4 * a5, 3520);
      while ( v13 )
      {
        if ( a5 >> 62 || (v14 = 4 * a5, v15 = _kmalloc_noprof(4 * a5, 3520), (v16 = v15) == 0) )
        {
          v25 = -12;
LABEL_38:
          kfree(v13);
          goto LABEL_39;
        }
        v17 = 0;
        v18 = 1;
        while ( 1 )
        {
          v19 = *(unsigned __int8 *)(v6 + 9049);
          v20 = *(unsigned __int8 *)(a4 + v17);
          v21 = *(unsigned __int16 *)(a3 + 2 * v17);
          if ( v19 == 15 )
          {
            v22 = 983040;
          }
          else
          {
            v23 = v19 < 0xE ? v19 + 1 : 0;
            *(_BYTE *)(v6 + 9049) = v23;
            v22 = v23 << 16;
          }
          v24 = 4 * v17;
          if ( (v17 & 0x8000000000000000LL) != 0 )
            break;
          if ( v14 < 4 * v17 )
            break;
          if ( v14 - 4 * v17 < 4 )
            break;
          *(_DWORD *)(v15 + 4 * v17) = (a2 << 20) | v21 | (v20 << 24) | v22;
          if ( v12 < v24 || v12 - v24 < 4 )
            break;
          *(_DWORD *)(v13 + 4 * v17) = (*(_DWORD *)(v6 + 9056) << 12) + 16416;
          v17 = v18++;
          if ( v17 >= a5 )
          {
            swr_master_bulk_write(v6, v13, v15, a5);
            kfree(v16);
            v25 = 0;
            goto LABEL_38;
          }
        }
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v28 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
        if ( a5 >> 62 )
        {
          v12 = 0;
          v13 = 0;
        }
        else
        {
          v12 = 4 * a5;
          v13 = _kmalloc_noprof(4 * a5, 3520);
        }
        *(_QWORD *)(StatusReg + 80) = v28;
      }
    }
    v25 = -12;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&swrm_bulk_write__rs_145, "swrm_bulk_write") )
      dev_err(a1, "%s: No support of Bulk write for master regs\n", "swrm_bulk_write");
    v25 = -22;
  }
LABEL_39:
  v29 = _pm_runtime_suspend(*(_QWORD *)(v6 + 8512), 13);
  v30 = *(_QWORD *)(v6 + 8512);
  *(_QWORD *)(v30 + 520) = ktime_get_mono_fast_ns(v29);
  return v25;
}
