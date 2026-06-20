__int64 __fastcall cvp_import_synx_v2(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  __int64 v4; // x21
  signed int v7; // w8
  unsigned int v8; // w22
  __int64 v9; // x26
  signed int v10; // w25
  unsigned int v11; // w0
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-48h]
  int v14; // [xsp+14h] [xbp-3Ch] BYREF
  __int64 v15; // [xsp+18h] [xbp-38h] BYREF
  __int64 v16; // [xsp+20h] [xbp-30h]
  __int64 v17; // [xsp+28h] [xbp-28h]
  int *v18; // [xsp+30h] [xbp-20h]
  __int64 v19; // [xsp+38h] [xbp-18h]
  __int64 v20; // [xsp+40h] [xbp-10h]
  __int64 v21; // [xsp+48h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 32);
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = nullptr;
  v15 = 0;
  v16 = 0;
  if ( v3 )
  {
    v4 = *(_QWORD *)(a1 + 15264);
    v7 = 0;
    v8 = 0;
    v9 = a2 + 44;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v10 = v7;
      v14 = *(_DWORD *)(a3 + 4LL * v7);
      if ( v14 )
      {
        v18 = &v14;
        LODWORD(v15) = 1;
        LODWORD(v17) = 5;
        if ( (unsigned int)v7 >= 0x41 )
          __break(0x5512u);
        v16 = v9 + 4LL * v7;
        v11 = synx_import(v4, &v15);
        if ( v11 )
        {
          if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          {
            v8 = v11;
          }
          else
          {
            v8 = v11;
            printk(&unk_84AED, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          }
        }
      }
      v7 = v10 + 1;
    }
    while ( (unsigned int)(v10 + 1) < *(_DWORD *)(a2 + 32) );
  }
  else
  {
    v8 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
