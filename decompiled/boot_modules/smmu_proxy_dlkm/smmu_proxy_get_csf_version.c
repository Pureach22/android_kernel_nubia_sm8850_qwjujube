__int64 __fastcall smmu_proxy_get_csf_version(_DWORD *a1)
{
  int v2; // w10
  __int64 result; // x0
  unsigned int client_env_object; // w0
  __int64 v6; // x0
  __int64 (__fastcall *v7)(__int64, _QWORD, __int64 **, __int64); // x8
  unsigned int v8; // w0
  __int64 v9; // x19
  __int64 (__fastcall *v10)(__int64, __int64, __int64 **, __int64); // x22
  __int64 v11; // x0
  unsigned int v12; // w0
  int v13; // w8
  int v14; // w9
  int v15; // w10
  unsigned int v16; // w20
  void (__fastcall *v17)(__int64, __int64, _QWORD, _QWORD); // x8
  __int64 v18; // x0
  __int64 (__fastcall *v19)(__int64, _QWORD, __int64 **, __int64); // [xsp+8h] [xbp-48h] BYREF
  __int64 v20; // [xsp+10h] [xbp-40h]
  __int64 v21; // [xsp+18h] [xbp-38h] BYREF
  int v22; // [xsp+20h] [xbp-30h]
  __int64 *v23; // [xsp+28h] [xbp-28h] BYREF
  __int64 v24; // [xsp+30h] [xbp-20h]
  __int64 (__fastcall *v25)(__int64, __int64, __int64 **, __int64); // [xsp+38h] [xbp-18h]
  __int64 v26; // [xsp+40h] [xbp-10h]
  __int64 v27; // [xsp+48h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = nullptr;
  v20 = 0;
  if ( cached_csf_version_0 )
  {
    *a1 = cached_csf_version_0;
    v2 = cached_csf_version_2;
    result = 0;
    a1[1] = cached_csf_version_1;
    a1[2] = v2;
    goto LABEL_18;
  }
  client_env_object = get_client_env_object(&v19);
  if ( client_env_object )
  {
    v16 = client_env_object;
    printk(&unk_7714, "smmu_proxy_get_csf_version");
  }
  else
  {
    LODWORD(v21) = 283;
    v7 = v19;
    v6 = v20;
    v25 = nullptr;
    v26 = 0;
    v23 = &v21;
    v24 = 4;
    if ( *((_DWORD *)v19 - 1) != 816020464 )
      __break(0x8228u);
    v8 = v7(v6, 0, &v23, 4097);
    v10 = v25;
    v9 = v26;
    if ( !v8 )
    {
      v11 = v26;
      v22 = 0;
      v21 = 0;
      v23 = &v21;
      v24 = 12;
      if ( *((_DWORD *)v25 - 1) != 816020464 )
        __break(0x8236u);
      v12 = v10(v11, 1, &v23, 16);
      v13 = v21;
      v14 = HIDWORD(v21);
      v15 = v22;
      *a1 = v21;
      a1[1] = v14;
      a1[2] = v15;
      cached_csf_version_2 = v15;
      cached_csf_version_1 = v14;
      cached_csf_version_0 = v13;
      v16 = v12;
      if ( !v10 )
        goto LABEL_13;
      goto LABEL_10;
    }
    v16 = v8;
    printk(&unk_7879, "smmu_proxy_get_csf_version");
    if ( v10 )
    {
LABEL_10:
      if ( *((_DWORD *)v10 - 1) != 816020464 )
        __break(0x8236u);
      v10(v9, 0xFFFF, nullptr, 0);
    }
  }
LABEL_13:
  v17 = (void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v19;
  if ( v19 )
  {
    v18 = v20;
    if ( *((_DWORD *)v19 - 1) != 816020464 )
      __break(0x8228u);
    v17(v18, 0xFFFF, 0, 0);
  }
  result = v16;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
