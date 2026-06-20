__int64 __fastcall _arm_smmu_iova_to_phys_hard(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 *v5; // x23
  __int64 v6; // x24
  int v7; // w26
  __int64 v8; // x19
  __int64 v9; // x22
  unsigned __int64 v10; // x3
  __int64 v11; // x1
  __int64 v12; // x8
  void (__fastcall *v13)(__int64 *, __int64, __int64, unsigned __int64); // x8
  __int64 v14; // x8
  __int64 v15; // x25
  char v16; // w0
  __int64 v17; // x8
  __int64 v18; // x1
  __int64 (__fastcall *v19)(__int64 *, __int64, __int64); // x8
  __int64 v20; // x0
  __int64 v21; // x23
  __int64 result; // x0
  __int64 (__fastcall *v23)(__int64, __int64); // x8
  __int64 v24; // x1
  __int64 *v25; // x0
  _QWORD v26[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = a1 - 56;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(__int64 **)(a1 - 184);
  v26[0] = a2;
  v6 = *(_QWORD *)(a1 - 168);
  v7 = *(unsigned __int8 *)(a1 - 136);
  v8 = *v5;
  v9 = raw_spin_lock_irqsave(a1 - 56);
  v10 = a2 & 0xFFFFFFFFFFFFF000LL;
  v11 = (unsigned int)(*((_DWORD *)v5 + 6) + v7);
  if ( *(_DWORD *)(a1 - 120) != 1 )
  {
    v14 = v5[6];
    if ( !v14 || (v13 = *(void (__fastcall **)(__int64 *, __int64, __int64, unsigned __int64))(v14 + 8)) == nullptr )
    {
      writel_relaxed_0(v10, (unsigned int *)(v5[1] + (int)((_DWORD)v11 << *((_DWORD *)v5 + 7)) + 2048));
      goto LABEL_8;
    }
    v25 = v5;
    if ( *((_DWORD *)v13 - 1) != -1008624849 )
      __break(0x8228u);
LABEL_36:
    v13(v25, v11, 2048, v10);
    goto LABEL_8;
  }
  v12 = v5[6];
  if ( v12 )
  {
    v13 = *(void (__fastcall **)(__int64 *, __int64, __int64, unsigned __int64))(v12 + 24);
    if ( v13 )
    {
      v25 = v5;
      if ( *((_DWORD *)v13 - 1) != 1922493645 )
        __break(0x8228u);
      goto LABEL_36;
    }
  }
  writeq_relaxed(a2 & 0xFFFFFFFFFFFFF000LL, (_QWORD *)(v5[1] + (int)((_DWORD)v11 << *((_DWORD *)v5 + 7)) + 2048));
LABEL_8:
  v15 = v5[1] + ((*((_DWORD *)v5 + 6) + v7) << *((_DWORD *)v5 + 7));
  v16 = readl(v15 + 2288);
  if ( (v16 & 1) != 0 )
  {
    _const_udelay(21475);
    __yield();
    v16 = readl(v15 + 2288);
    if ( (v16 & 1) != 0 )
    {
      _const_udelay(21475);
      __yield();
      v16 = readl(v15 + 2288);
      if ( (v16 & 1) != 0 )
      {
        _const_udelay(21475);
        __yield();
        v16 = readl(v15 + 2288);
        if ( (v16 & 1) != 0 )
        {
          _const_udelay(21475);
          __yield();
          v16 = readl(v15 + 2288);
          if ( (v16 & 1) != 0 )
          {
            _const_udelay(21475);
            __yield();
            v16 = readl(v15 + 2288);
            if ( (v16 & 1) != 0 )
            {
              _const_udelay(21475);
              __yield();
              v16 = readl(v15 + 2288);
              if ( (v16 & 1) != 0 )
              {
                _const_udelay(21475);
                __yield();
                v16 = readl(v15 + 2288);
                if ( (v16 & 1) != 0 )
                {
                  _const_udelay(21475);
                  __yield();
                  v16 = readl(v15 + 2288);
                  if ( (v16 & 1) != 0 )
                  {
                    _const_udelay(21475);
                    __yield();
                    v16 = readl(v15 + 2288);
                    if ( (v16 & 1) != 0 )
                    {
                      _const_udelay(21475);
                      __yield();
                      v16 = readl(v15 + 2288);
                      if ( (v16 & 1) != 0 )
                        v16 = readl(v15 + 2288);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (v16 & 1) != 0 )
  {
    raw_spin_unlock_irqrestore(v2, v9);
    dev_err(v8, "iova to phys timed out on %pad. Falling back to software table walk.\n", v26);
    v23 = *(__int64 (__fastcall **)(__int64, __int64))(v6 + 16);
    v24 = v26[0];
    if ( *((_DWORD *)v23 - 1) != 1371081757 )
      __break(0x8228u);
    result = v23(v6, v24);
  }
  else
  {
    v17 = v5[6];
    v18 = (unsigned int)(*((_DWORD *)v5 + 6) + v7);
    if ( v17 && (v19 = *(__int64 (__fastcall **)(__int64 *, __int64, __int64))(v17 + 16)) != nullptr )
    {
      if ( *((_DWORD *)v19 - 1) != 1426685181 )
        __break(0x8228u);
      v20 = v19(v5, v18, 80);
    }
    else
    {
      v20 = readq_relaxed((_QWORD *)(v5[1] + (int)((_DWORD)v18 << *((_DWORD *)v5 + 7)) + 80));
    }
    v21 = v20;
    raw_spin_unlock_irqrestore(v2, v9);
    if ( (v21 & 1) != 0 )
    {
      dev_err(v8, "translation fault!\n");
      dev_err(v8, "PAR = 0x%llx\n", v21);
      result = 0;
    }
    else
    {
      result = v21 & 0xFFFFFFF000LL | a2 & 0xFFF;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
