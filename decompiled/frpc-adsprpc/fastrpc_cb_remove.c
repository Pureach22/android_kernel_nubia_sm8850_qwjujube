__int64 __fastcall fastrpc_cb_remove(__int64 a1)
{
  __int64 v1; // x22
  _QWORD *v2; // x25
  __int64 v3; // x0
  _QWORD *v4; // x20
  __int64 v5; // x9
  __int64 v6; // x19
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 v9; // x26
  __int64 v10; // x27
  unsigned __int64 v11; // x8
  __int64 v12; // x28
  unsigned __int64 i; // x25
  __int64 v14; // x24
  _QWORD *v15; // x23
  __int64 v16; // x0
  _QWORD *v17; // x20
  __int64 domain_for_dev; // x0
  __int64 v19; // x8
  __int64 v21; // x0
  _QWORD *v22; // x8
  __int64 v23; // x10
  _QWORD *v24; // x28
  unsigned __int64 v25; // x8
  __int64 v26; // x9
  __int64 v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(a1 + 168);
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 112) + 152LL);
  if ( *(_DWORD *)(*(_QWORD *)(v28 + 128) + 1008LL) == 1 && *(_DWORD *)(v1 + 64160) )
  {
    v2 = (_QWORD *)(v1 + 64144);
    v3 = raw_spin_lock_irqsave(v1 + 51600);
    v4 = *(_QWORD **)(v1 + 64144);
    v5 = v3;
    if ( (_QWORD *)*v2 == v2 )
    {
LABEL_4:
      raw_spin_unlock_irqrestore(v1 + 51600, v5);
    }
    else
    {
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v22 = (_QWORD *)v4[1];
        if ( (_QWORD *)*v22 == v4 && (v23 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
        {
          *(_QWORD *)(v23 + 8) = v22;
          *v22 = v23;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
        }
        *v4 = 0xDEAD000000000100LL;
        v4[1] = 0xDEAD000000000122LL;
        --*(_DWORD *)(v1 + 64160);
        raw_spin_unlock_irqrestore(v1 + 51600, v5);
        if ( !v4 )
          break;
        if ( *((_DWORD *)v4 + 14) == 4 )
        {
          _fastrpc_dma_buf_free(v4);
          kfree(v4);
        }
        else
        {
          v24 = (_QWORD *)v4[5];
          mutex_lock(v24 + 2);
          if ( *v24 )
          {
            v25 = v4[9];
            v26 = 4095;
            if ( v25 > 0x200000 )
              v26 = 0x1FFFFF;
            if ( v25 > 0x40000000 )
              v26 = 0x3FFFFFFF;
            v24[12] -= (v26 + v25) & ~v26;
            _fastrpc_dma_buf_free(v4);
            kfree(v4);
          }
          mutex_unlock(v24 + 2);
        }
        v21 = raw_spin_lock_irqsave(v1 + 51600);
        v4 = (_QWORD *)*v2;
        v5 = v21;
        if ( (_QWORD *)*v2 == v2 )
          goto LABEL_4;
      }
    }
  }
  v6 = v28;
  v7 = raw_spin_lock_irqsave(v1 + 51600);
  v8 = 0;
  v9 = v1;
  do
  {
    v29 = v8;
    v10 = v1 + 176 + (v8 << 10);
    v11 = *(unsigned int *)(v10 + 1016);
    if ( (_DWORD)v11 )
    {
      v12 = 0;
      for ( i = 0; i < v11; ++i )
      {
        if ( v12 == 1152 )
        {
          __break(0x5512u);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          JUMPOUT(0x19228);
        }
        v14 = v9 + v12;
        if ( *(_DWORD *)(v9 + v12 + 184) == *(_DWORD *)(v6 + 8) )
        {
          v15 = (_QWORD *)(v14 + 176);
          raw_spin_unlock_irqrestore(v1 + 51600, v7);
          mutex_lock(v14 + 192);
          if ( v14 != -176 )
          {
            v16 = *(_QWORD *)(v14 + 240);
            if ( v16 )
            {
              v17 = *(_QWORD **)(v9 + v12 + 248);
              gen_pool_destroy(v16);
              *(_QWORD *)(v14 + 240) = 0;
              if ( v17 )
              {
                if ( *v15 )
                {
                  domain_for_dev = iommu_get_domain_for_dev(*v15);
                  iommu_unmap(domain_for_dev, *(_QWORD *)(v9 + v12 + 256), *(_QWORD *)(v9 + v12 + 264));
                  v19 = v17[8];
                  if ( v19 )
                    dma_free_attrs(v17[4], v17[9], v17[6], v19 & ~(-1LL << *(_DWORD *)(v9 + v12 + 316)), 0);
                  kfree(v17);
                  v6 = v28;
                  *(_QWORD *)(v9 + v12 + 248) = 0;
                }
              }
            }
          }
          *v15 = 0;
          mutex_unlock(v14 + 192);
          v7 = raw_spin_lock_irqsave(v1 + 51600);
          *(_BYTE *)(v9 + v12 + 188) = 0;
          v11 = *(unsigned int *)(v10 + 1016);
          --*(_DWORD *)(v1 + 4);
        }
        v12 += 144;
      }
    }
    v9 += 1024;
    v8 = v29 + 1;
  }
  while ( v29 != 49 );
  raw_spin_unlock_irqrestore(v1 + 51600, v7);
  return dev_info(a1 + 16, "Successfully removed %s", *(const char **)(a1 + 16));
}
