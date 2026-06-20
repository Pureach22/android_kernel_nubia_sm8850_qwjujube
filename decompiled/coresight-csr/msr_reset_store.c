__int64 __fastcall msr_reset_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 result; // x0
  unsigned __int64 v6; // x19
  unsigned __int64 v7; // x8
  int v9; // w8
  _DWORD *v10; // x8
  __int64 v11; // x1
  __int64 v12; // x10
  int v13; // w8
  unsigned __int64 v14; // x9
  int v15; // w11
  __int64 v16; // x19
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  result = -22;
  v6 = *(_QWORD *)(v4 + 152);
  if ( v6 )
  {
    if ( v6 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(v6 + 162) == 1 )
    {
      v7 = *(_QWORD *)(v6 + 48);
      if ( v7 )
      {
        if ( v7 <= 0xFFFFFFFFFFFFF000LL )
        {
          v17[0] = 0;
          v9 = kstrtoull(a3, 0, v17);
          result = -22;
          if ( !v9 && v17[0] == 1 )
          {
            v10 = *(_DWORD **)(v6 + 56);
            if ( *v10 )
            {
              *v10 = 0;
              v11 = raw_spin_lock_irqsave(v6 + 152);
              *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = -978530731;
              __dsb(0xFu);
              v12 = *(_QWORD *)(v6 + 16);
              if ( (unsigned __int64)(*(_QWORD *)(v6 + 24) - v12 + 1) >= 4 )
              {
                v13 = 0;
                v14 = 0;
                v15 = 1;
                do
                {
                  *(_DWORD *)(*(_QWORD *)v6 + v12 + v13) = 0;
                  v13 += 4;
                  *(_DWORD *)(*(_QWORD *)(v6 + 48) + 4 * v14) = 0;
                  v14 = v15++;
                  v12 = *(_QWORD *)(v6 + 16);
                }
                while ( v14 < (unsigned __int64)(*(_QWORD *)(v6 + 24) - v12 + 1) >> 2 );
              }
              __dsb(0xFu);
              *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = 0;
              raw_spin_unlock_irqrestore(v6 + 152, v11);
              v16 = *(_QWORD *)(v6 + 144);
              clk_disable(v16);
              clk_unprepare(v16);
              result = a4;
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
