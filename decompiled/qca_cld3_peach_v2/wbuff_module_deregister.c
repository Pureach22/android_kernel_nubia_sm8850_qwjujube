__int64 __fastcall wbuff_module_deregister(unsigned __int8 *a1)
{
  __int64 result; // x0
  unsigned __int64 v3; // x8
  char *v4; // x19
  char *v5; // x19
  int v6; // t1
  __int64 v7; // x21
  unsigned __int64 StatusReg; // x8
  _QWORD *v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x20
  __int64 v15; // x21
  unsigned __int64 v16; // x8
  __int64 v17; // x23
  _QWORD *v18; // x24
  __int64 v19; // x8

  result = 4;
  if ( a1 )
  {
    if ( (wbuff[0] & 1) != 0 )
    {
      v3 = *a1;
      if ( v3 <= 1 )
      {
        v4 = &wbuff[808 * (unsigned int)v3];
        v6 = (unsigned __int8)v4[8];
        v5 = v4 + 8;
        if ( v6 == 1 )
        {
          v7 = 808LL * (unsigned int)v3;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v9 = (_QWORD *)raw_spin_lock(v5 + 8);
          }
          else
          {
            v9 = (_QWORD *)raw_spin_lock_bh(v5 + 8);
            *((_QWORD *)v5 + 2) |= 1uLL;
          }
          v14 = 0;
          v15 = v7 + 48;
          while ( 1 )
          {
            v16 = v15 + 48 * v14;
            if ( v16 > 0x67F )
              break;
            v17 = (__int64)&v5[48 * v14 + 40];
            if ( *(_BYTE *)v17 == 1 )
            {
              if ( v16 > 0x677 )
                break;
              v9 = *(_QWORD **)(v17 + 8);
              if ( v9 )
              {
                do
                {
                  v18 = (_QWORD *)*v9;
                  _qdf_nbuf_free((__int64)v9);
                  v9 = v18;
                }
                while ( v18 );
              }
              *(_QWORD *)(v17 + 32) = 0;
              *(_QWORD *)(v17 + 40) = 0;
              *(_QWORD *)(v17 + 24) = 0;
            }
            if ( ++v14 == 16 )
            {
              v19 = *((_QWORD *)v5 + 2);
              *v5 = 0;
              if ( (v19 & 1) != 0 )
              {
                *((_QWORD *)v5 + 2) = v19 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v5 + 8);
              }
              else
              {
                raw_spin_unlock(v5 + 8);
              }
              return 0;
            }
          }
          __break(1u);
          if ( (v11 & 0x1000) == 0 )
            JUMPOUT(0x736220);
          return wbuff_module_register(v9, v10, v11, v12, v13);
        }
      }
    }
  }
  return result;
}
