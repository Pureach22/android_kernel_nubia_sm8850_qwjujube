__int64 __fastcall _fastrpc_free_map(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  _QWORD *v3; // x8
  __int64 v4; // x9
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x1
  int v8; // w0
  _QWORD *v9; // x20
  unsigned __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = *(_QWORD *)(result + 16);
    v2 = result;
    if ( v1 )
    {
      raw_spin_lock(v1 + 320);
      v3 = *(_QWORD **)(v2 + 8);
      if ( *v3 == v2 && (v4 = *(_QWORD *)v2, *(_QWORD *)(*(_QWORD *)v2 + 8LL) == v2) )
      {
        *(_QWORD *)(v4 + 8) = v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      v5 = *(_QWORD *)(v2 + 16) + 320LL;
      *(_QWORD *)v2 = 0xDEAD000000000100LL;
      *(_QWORD *)(v2 + 8) = 0xDEAD000000000122LL;
      raw_spin_unlock(v5);
      if ( !*(_QWORD *)(v2 + 40) )
        goto LABEL_21;
      if ( (*(_BYTE *)(v2 + 104) & 1) != 0 )
      {
        v6 = *(_QWORD *)(v2 + 64);
        v7 = *(_QWORD *)(v2 + 72);
        v12 = (1LL << *(_DWORD *)(*(_QWORD *)(v1 + 128) + 32LL)) | 8;
        v13[0] = 0x700000003LL;
        v8 = qcom_scm_assign_mem(v6, v7, &v12, v13, 1);
        if ( v8 )
        {
          dev_err(
            *(_QWORD *)(*(_QWORD *)(v1 + 128) + 168LL),
            "Failed to assign memory phys 0x%llx size 0x%llx err %d",
            *(_QWORD *)(v2 + 64),
            *(_QWORD *)(v2 + 72),
            v8);
LABEL_21:
          result = kfree(v2);
          goto LABEL_22;
        }
      }
    }
    else if ( !*(_QWORD *)(result + 40) )
    {
      goto LABEL_21;
    }
    if ( (*(_BYTE *)(v2 + 104) & 0x10) != 0 || *(_DWORD *)(v2 + 108) == 16 )
    {
      dma_buf_unmap_attachment_wrap(v2);
      dma_buf_detach(*(_QWORD *)(v2 + 32), *(_QWORD *)(v2 + 48));
      dma_buf_put(*(_QWORD *)(v2 + 32));
    }
    else
    {
      v9 = *(_QWORD **)(v2 + 56);
      mutex_lock(v9 + 2);
      if ( *v9 )
      {
        dma_buf_unmap_attachment_wrap(v2);
        dma_buf_detach(*(_QWORD *)(v2 + 32), *(_QWORD *)(v2 + 48));
        dma_buf_put(*(_QWORD *)(v2 + 32));
        v10 = *(_QWORD *)(v2 + 72);
        v11 = 4095;
        if ( v10 > 0x200000 )
          v11 = 0x1FFFFF;
        if ( v10 > 0x40000000 )
          v11 = 0x3FFFFFFF;
        v9[12] -= (v11 + v10) & ~v11;
      }
      mutex_unlock(v9 + 2);
    }
    goto LABEL_21;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
