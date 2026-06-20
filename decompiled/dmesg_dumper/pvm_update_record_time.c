__int64 __fastcall pvm_update_record_time(__int64 *a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w22
  int v6; // w24
  _QWORD *v7; // x8
  unsigned __int64 v8; // x10
  __int64 v9; // x11
  unsigned __int64 v10; // x9
  __int64 v11; // x13
  __int64 v12; // x25
  __int64 v13; // x26
  __int64 v14; // x12
  __int64 v15; // x12
  __int64 v16; // x12
  __int64 v17; // x12
  __int64 v18; // x12
  __int64 v19; // x14
  __int64 v20; // x11
  _QWORD v21[3]; // [xsp+8h] [xbp-18h] BYREF

  v21[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v21[1] = 0;
  result = gh_get_virt_time_offset(v21);
  v5 = 0;
  v6 = 0;
  do
  {
    v7 = (_QWORD *)(a2 + 16LL * v6);
    v8 = a1[14];
    v9 = a1[15];
    v10 = v7[1];
    if ( v10 > v8 || !v9 && *v7 )
    {
      v11 = a1[3];
      v13 = *a1;
      v12 = a1[1];
      *a1 = a1[2];
      a1[1] = v11;
      v14 = a1[5];
      a1[2] = a1[4];
      a1[3] = v14;
      v15 = a1[7];
      a1[4] = a1[6];
      a1[5] = v15;
      v16 = a1[9];
      a1[6] = a1[8];
      a1[7] = v16;
      v17 = a1[11];
      a1[8] = a1[10];
      a1[9] = v17;
      v19 = a1[12];
      v18 = a1[13];
      a1[12] = v8;
      a1[13] = v9;
      v20 = v21[0];
      a1[10] = v19;
      a1[11] = v18;
      a1[14] = v7[1];
      a1[15] = *v7 - v20;
      if ( v10 == v7[1] )
      {
        result = printk(&unk_7C2F);
      }
      else
      {
        result = reverse_rec_time(a1);
        *a1 = v13;
        a1[1] = v12;
        ++v5;
        v6 = -1;
      }
    }
    if ( v6 > 6 )
      break;
    ++v6;
  }
  while ( v5 < 5000 );
  _ReadStatusReg(SP_EL0);
  return result;
}
