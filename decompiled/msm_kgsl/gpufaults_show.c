__int64 __fastcall gpufaults_show(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v3; // x22
  __int64 v5; // x25
  __int64 v6; // x25
  __int64 v7; // x25
  __int64 v8; // x25
  __int64 v9; // x25
  __int64 v10; // x25
  __int64 v11; // x25
  __int64 v12; // x20

  v3 = *(_DWORD **)(a1 + 152);
  raw_read_lock(v3 + 6071);
  v5 = (int)scnprintf(a3, 4094, "%u ", v3[6013]);
  v6 = v5 + (int)scnprintf(a3 + v5, 4094 - v5, "%u ", v3[6014]);
  v7 = v6 + (int)scnprintf(a3 + v6, 4094 - v6, "%u ", v3[6015]);
  v8 = v7 + (int)scnprintf(a3 + v7, 4094 - v7, "%u ", v3[6016]);
  v9 = v8 + (int)scnprintf(a3 + v8, 4094 - v8, "%u ", v3[6017]);
  v10 = v9 + (int)scnprintf(a3 + v9, 4094 - v9, "%u ", v3[6018]);
  v11 = v10 + (int)scnprintf(a3 + v10, 4094 - v10, "%u ", v3[6019]);
  v12 = v11 + (int)scnprintf(a3 + v11, 4094 - v11, "%u ", v3[6020]);
  raw_read_unlock(v3 + 6071);
  *(_BYTE *)(a3 + v12) = 10;
  return v12 + 1;
}
