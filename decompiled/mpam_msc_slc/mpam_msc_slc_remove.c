__int64 __fastcall mpam_msc_slc_remove(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x0
  unsigned int (__fastcall **v6)(__int64, __int64 *, __int64, __int64, __int64); // x9
  unsigned int (__fastcall *v7)(__int64, __int64 *, __int64, __int64, __int64); // x8
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  int v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v1 = result;
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 168);
  if ( v2 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(v2 + 16) + 28LL) )
    {
      result = dev_err(result + 16, "Monitors are configured!\n");
      goto LABEL_9;
    }
    *(_DWORD *)(v2 + 88) = 2;
    v3 = *(_QWORD *)(result + 168);
    if ( !v3 )
      goto LABEL_10;
    v4 = *(unsigned int *)(v3 + 12);
    v9 = 0;
    v8 = v4;
    v6 = *(unsigned int (__fastcall ***)(__int64, __int64 *, __int64, __int64, __int64))(v3 + 40);
    v5 = *(_QWORD *)(v3 + 48);
    v7 = *v6;
    if ( *((_DWORD *)*v6 - 1) != 1737159351 )
      __break(0x8228u);
    if ( v7(v5, &v8, 0x534C434D50414DLL, 4, 12) )
LABEL_10:
      dev_err(v1 + 16, "Failed to stop SLC Monitor thread\n");
    result = detach_mpam_msc(v1 + 16, v2, 2);
    *(_DWORD *)(v2 + 88) = 1;
  }
  *(_QWORD *)(v1 + 168) = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
