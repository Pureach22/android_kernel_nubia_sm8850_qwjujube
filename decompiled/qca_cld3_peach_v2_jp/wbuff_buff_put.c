__int64 __fastcall wbuff_buff_put(__int64 a1)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x8
  char *v3; // x20
  char *v4; // x21
  char *v5; // x21
  int v6; // t1
  __int64 v7; // x22
  unsigned __int64 v8; // x23
  __int64 v9; // x1
  __int64 v10; // x8
  int v11; // w10
  unsigned __int64 v12; // x9
  int v13; // w8
  int v14; // w10
  int v15; // w10
  unsigned __int64 StatusReg; // x8
  __int16 v17; // w8
  __int64 v18; // x8

  v1 = a1;
  if ( (int)_qdf_nbuf_get_users(a1) <= 1 && wbuff[0] == 1 )
  {
    v2 = *(_QWORD *)(v1 + 16);
    if ( v2 )
    {
      if ( (v2 & 0xE0) == 0 )
      {
        v3 = &wbuff[808 * ((v2 >> 4) & 1) + 8];
        v4 = &v3[48 * ((v2 >> 1) & 7)];
        v6 = (unsigned __int8)v4[40];
        v5 = v4 + 40;
        if ( v6 == 1 )
        {
          v7 = *(int *)&wbuff[808 * ((v2 >> 4) & 1) + 36];
          v8 = *(int *)&wbuff[808 * ((v2 >> 4) & 1) + 40];
          skb_push(v1, (unsigned int)(*(_DWORD *)(v1 + 224) - *(_DWORD *)(v1 + 216)));
          if ( *(_DWORD *)(v1 + 116) )
            v9 = 0;
          else
            v9 = (unsigned int)(*(_DWORD *)(v1 + 212) - *(_DWORD *)(v1 + 208));
          skb_put(v1, v9);
          memset(*(void **)(v1 + 224), 0, *(unsigned int *)(v1 + 112));
          skb_trim(v1, 0);
          v10 = *(_QWORD *)(v1 + 224);
          v11 = *(_DWORD *)(v1 + 208);
          *(_QWORD *)(v1 + 40) = 0;
          *(_QWORD *)(v1 + 48) = 0;
          *(_QWORD *)(v1 + 56) = 0;
          *(_QWORD *)(v1 + 64) = 0;
          v12 = v10 + 64;
          v13 = v11 + 64;
          *(_QWORD *)(v1 + 224) = v12;
          *(_DWORD *)(v1 + 208) = v11 + 64;
          *(_QWORD *)(v1 + 72) = 0;
          *(_QWORD *)(v1 + 80) = 0;
          *(_BYTE *)(v1 + 68) = 3;
          if ( (_DWORD)v8 )
          {
            v14 = v12 % v8;
            if ( v14 )
            {
              v15 = v8 - v14;
              v12 += v15;
              v13 += v15;
            }
          }
          *(_QWORD *)(v1 + 224) = v12 + v7;
          *(_DWORD *)(v1 + 208) = v13 + v7;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v3 + 8);
          }
          else
          {
            raw_spin_lock_bh(v3 + 8);
            *((_QWORD *)v3 + 2) |= 1uLL;
          }
          if ( *v3 == 1 )
          {
            *(_QWORD *)v1 = *((_QWORD *)v5 + 1);
            v17 = *((_WORD *)v3 + 1);
            *((_QWORD *)v5 + 1) = v1;
            v1 = 0;
            *((_WORD *)v3 + 1) = v17 - 1;
          }
          v18 = *((_QWORD *)v3 + 2);
          if ( (v18 & 1) != 0 )
          {
            *((_QWORD *)v3 + 2) = v18 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v3 + 8);
          }
          else
          {
            raw_spin_unlock(v3 + 8);
          }
        }
      }
    }
  }
  return v1;
}
