__int64 __fastcall qrtr_get_service_id(unsigned int a1, int a2)
{
  __int64 v4; // x0
  __int64 v5; // x21
  unsigned int *v6; // x0
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = xa_load(&nodes, a1);
  if ( v4 && (v5 = v4, v8[0] = 0, (v6 = (unsigned int *)xa_find(v4 + 8, v8, -1, 8)) != nullptr) )
  {
    while ( v6[2] != a1 || v6[3] != a2 )
    {
      v6 = (unsigned int *)xa_find_after(v5 + 8, v8, -1, 8);
      if ( !v6 )
        goto LABEL_3;
    }
    result = *v6;
  }
  else
  {
LABEL_3:
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
