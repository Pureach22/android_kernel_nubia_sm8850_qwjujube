__int64 __fastcall geni_i3c_send_setdasa(__int64 a1, unsigned __int8 a2, char a3)
{
  _BYTE *v5; // x0
  unsigned int v6; // w19
  _WORD v8[2]; // [xsp+8h] [xbp-38h] BYREF
  int v9; // [xsp+Ch] [xbp-34h]
  _QWORD *v10; // [xsp+10h] [xbp-30h]
  int v11; // [xsp+18h] [xbp-28h]
  int v12; // [xsp+1Ch] [xbp-24h]
  _QWORD v13[2]; // [xsp+20h] [xbp-20h] BYREF
  _BYTE *v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = a2;
  v13[1] = 1;
  v5 = (_BYTE *)_kmalloc_cache_noprof(sched_clock, 3520, 1);
  v14 = v5;
  if ( v5 )
  {
    v8[1] = 0;
    v10 = v13;
    v12 = 0;
    *v5 = 2 * a3;
    v8[0] = -30976;
    v9 = 1;
    v11 = 0;
    v6 = geni_i3c_master_send_ccc_cmd(a1, v8);
    kfree(v14);
  }
  else
  {
    v6 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
