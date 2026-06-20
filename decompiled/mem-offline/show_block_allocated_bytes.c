__int64 __fastcall show_block_allocated_bytes(const char **a1, __int64 a2, __int64 a3)
{
  const char *v4; // x0
  __int64 v5; // x0
  __int64 v6; // x20
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x22
  __int64 v9; // x3
  unsigned __int64 v10; // x23
  unsigned __int64 v11; // x21
  __int64 v12; // x20
  __int64 v13; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x28
  __int64 v20; // x8
  unsigned __int64 v21; // x8
  __int64 v22; // x22
  __int64 result; // x0
  __int64 v24; // [xsp+0h] [xbp-10h] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v24 = 0;
  v5 = sscanf(v4, "memory%lu", &v24);
  if ( (_DWORD)v5 == 1 )
  {
    v6 = v24;
    v7 = memory_block_size_bytes(v5);
    if ( MEMORY[0xC780] && MEMORY[0xC778] )
    {
      v8 = v6 << 15;
      v9 = 0;
      if ( MEMORY[0xC768] + MEMORY[0xC778] > (unsigned __int64)(v6 << 15) )
      {
        v10 = v8 + (v7 >> 12);
        if ( v10 > MEMORY[0xC768] )
        {
          v11 = v7;
          v12 = raw_spin_lock_irqsave(0xCC70u);
          if ( v8 < v10 )
          {
            v13 = 0;
            StatusReg = _ReadStatusReg(SP_EL0);
            while ( 1 )
            {
              if ( v8 >> 52 || v8 >> 36 )
                goto LABEL_17;
              v15 = (_QWORD *)mem_section;
              if ( mem_section )
              {
                v15 = *(_QWORD **)(mem_section + ((v8 >> 19) & 0x1FFFFFFFFFF8LL));
                if ( v15 )
                  v15 += 4 * ((v8 >> 15) & 0x7F);
              }
              ++*(_DWORD *)(StatusReg + 16);
              if ( v15 && (*v15 & 2) != 0 )
              {
                if ( (*v15 & 8) != 0 )
                {
                  LODWORD(v19) = 1;
                }
                else
                {
                  v18 = v15[1];
                  if ( v18 )
                    v19 = (*(_QWORD *)(v18 + 16) >> (v8 >> 9)) & 1LL;
                  else
                    LODWORD(v19) = 0;
                }
                v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
                *(_DWORD *)(StatusReg + 16) = v20;
                if ( v20 && *(_QWORD *)(StatusReg + 16) )
                {
                  if ( !(_DWORD)v19 )
                    goto LABEL_17;
                  goto LABEL_28;
                }
              }
              else
              {
                v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
                *(_DWORD *)(StatusReg + 16) = v16;
                if ( v16 && *(_QWORD *)(StatusReg + 16) )
                  goto LABEL_17;
                LODWORD(v19) = 0;
              }
              preempt_schedule();
              if ( !(_DWORD)v19 )
                goto LABEL_17;
LABEL_28:
              v21 = 0xFFFFFFFEC0000000LL - ((__int64)memstart_addr >> 12 << 6) + (v8 << 6);
              if ( *(unsigned __int8 *)(v21 + 51) == 240 )
              {
                v17 = 1 << *(_DWORD *)(v21 + 40);
                v13 += v17;
                goto LABEL_18;
              }
LABEL_17:
              v17 = 1;
LABEL_18:
              v8 += v17;
              if ( v8 >= v10 )
              {
                v22 = v13 << 12;
                goto LABEL_35;
              }
            }
          }
          v22 = 0;
LABEL_35:
          raw_spin_unlock_irqrestore(0xCC70u, v12);
          v9 = v11 - v22;
        }
      }
    }
    else
    {
      v9 = 0;
    }
    result = (int)scnprintf(a3, 100, "%lu\n", v9);
  }
  else
  {
    printk(&unk_9C4C);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
