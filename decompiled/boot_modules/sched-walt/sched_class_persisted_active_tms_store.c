__int64 __fastcall sched_class_persisted_active_tms_store(int a1, int a2, char *src, __int64 a4)
{
  unsigned __int8 *v5; // x0
  int v6; // w8
  int v7; // w9
  int v8; // t1
  unsigned int v9; // w11
  unsigned __int8 *v10; // x10
  int v11; // w11
  int v12; // t1
  unsigned int v13; // w20
  char dest[256]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v16; // [xsp+108h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest[255] = 0;
  strncpy(dest, src, 0xFFu);
  v5 = (unsigned __int8 *)strim(dest);
  v6 = *v5;
  if ( v6 == 45 || v6 == 43 )
  {
    v8 = *++v5;
    v7 = v8;
  }
  else
  {
    v7 = *v5;
  }
  if ( (unsigned int)(v7 - 48) > 9 )
  {
    v9 = 0;
  }
  else
  {
    v9 = 0;
    v10 = v5 + 1;
    do
    {
      v11 = v7 + 10 * v9;
      v12 = *v10++;
      v7 = v12;
      v9 = v11 - 48;
    }
    while ( (unsigned int)(v12 - 48) < 0xA );
  }
  if ( v6 == 45 )
    v13 = -v9;
  else
    v13 = v9;
  mutex_lock(&scp_data_lock);
  if ( v13 <= 0xEA60 )
    qword_6A598 = 1000000LL * v13;
  mutex_unlock(&scp_data_lock);
  _ReadStatusReg(SP_EL0);
  return a4;
}
