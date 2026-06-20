__int64 __fastcall slim_stream_disable(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 (__fastcall *v3)(_QWORD); // x8
  unsigned int v4; // w21
  __int64 result; // x0
  __int64 v6; // x21
  __int64 v7; // x22
  __int64 v8; // x28
  __int64 v9; // x9
  char v10; // w8
  __int64 v11; // x23
  _QWORD *v12; // x0
  _QWORD v13[3]; // [xsp+0h] [xbp-60h] BYREF
  int v14; // [xsp+18h] [xbp-48h] BYREF
  __int16 v15; // [xsp+1Ch] [xbp-44h]
  char v16; // [xsp+1Eh] [xbp-42h]
  char v17; // [xsp+1Fh] [xbp-41h]
  __int128 *v18; // [xsp+20h] [xbp-40h]
  __int64 v19; // [xsp+28h] [xbp-38h]
  __int128 v20; // [xsp+30h] [xbp-30h] BYREF
  char *v21; // [xsp+40h] [xbp-20h]
  __int64 v22; // [xsp+48h] [xbp-18h]
  char v23; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+58h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0xFF00000003400003LL;
  v13[1] = 0;
  v13[2] = 0;
  if ( !a1 )
  {
    printk(&unk_87EB, "slim_stream_disable");
    goto LABEL_17;
  }
  if ( !*(_QWORD *)(a1 + 40) || !*(_DWORD *)(a1 + 36) )
  {
    printk(&unk_8819, "slim_stream_disable");
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  v2 = *(_QWORD **)(*(_QWORD *)(a1 + 8) + 920LL);
  if ( !v2[37] )
    goto LABEL_8;
  mutex_lock(v2 + 39);
  v3 = (__int64 (__fastcall *)(_QWORD))v2[37];
  if ( *((_DWORD *)v3 - 1) != 843195780 )
    __break(0x8228u);
  v4 = v3(a1);
  mutex_unlock(v2 + 39);
  result = v4;
  if ( !v4 )
  {
LABEL_8:
    result = slim_do_transfer(v2, (unsigned __int8 *)v13);
    if ( !(_DWORD)result )
    {
      if ( *(int *)(a1 + 36) >= 1 )
      {
        v6 = 0;
        v7 = 0;
        do
        {
          v8 = *(_QWORD *)(a1 + 8);
          v9 = *(_QWORD *)(a1 + 40);
          v19 = 0;
          v20 = 0x10000u;
          v10 = *(_BYTE *)(v8 + 932);
          v11 = v9 + v6;
          *(_QWORD *)((char *)&v20 + 3) = 0;
          v12 = *(_QWORD **)(v8 + 920);
          v21 = &v23;
          v22 = 0;
          v14 = 5570565;
          v15 = 0;
          v16 = 0;
          v17 = v10;
          v18 = &v20;
          v23 = *(_DWORD *)(v9 + v6 + 12);
          if ( !(unsigned int)slim_do_transfer(v12, (unsigned __int8 *)&v14) )
          {
            BYTE2(v14) = 88;
            *(_DWORD *)(v11 + 32) = 6;
            slim_do_transfer(*(_QWORD **)(v8 + 920), (unsigned __int8 *)&v14);
          }
          ++v7;
          v6 += 36;
        }
        while ( v7 < *(int *)(a1 + 36) );
      }
      BYTE2(v13[0]) = 95;
      result = slim_do_transfer(v2, (unsigned __int8 *)v13);
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
