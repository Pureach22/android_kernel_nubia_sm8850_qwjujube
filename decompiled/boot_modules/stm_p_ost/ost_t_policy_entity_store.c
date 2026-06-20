__int64 __fastcall ost_t_policy_entity_store(__int64 a1, const char *a2, __int64 a3)
{
  __int64 v5; // x22
  int *v6; // x20
  int v8; // w8
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  __int16 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 56) + 96LL);
  v6 = (int *)to_pdrv_policy_node();
  v11 = 0;
  v10 = 0;
  mutex_lock(v5 + 136);
  LODWORD(a2) = sscanf(a2, "%s", &v10);
  mutex_unlock(v5 + 136);
  if ( (_DWORD)a2 != 1 )
    goto LABEL_7;
  if ( (_DWORD)v10 == 1634890854 && *(_DWORD *)((char *)&v10 + 3) == 6644577 )
  {
    v8 = 1;
LABEL_10:
    *v6 = v8;
    goto LABEL_11;
  }
  if ( !((unsigned int)v10 ^ 0x67616964 | BYTE4(v10)) )
  {
    v8 = 2;
    goto LABEL_10;
  }
LABEL_7:
  a3 = -22;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return a3;
}
