__int64 __fastcall sched_nbia_rbuffer_size_store(int a1, int a2, char *src, __int64 a4)
{
  unsigned __int8 *v5; // x0
  int v6; // w8
  int v7; // w9
  int v8; // t1
  int v9; // w11
  unsigned __int8 *v10; // x10
  int v11; // w11
  int v12; // t1
  int v13; // w20
  void (*v14)(void); // x8
  void (*v15)(void); // x8
  char dest[256]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v18; // [xsp+108h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest[255] = 0;
  strncpy(dest, src, 0xFFu);
  printk(&unk_635FE);
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
  if ( (unsigned int)(v13 - 1) >> 4 <= 0x270 )
  {
    mutex_lock(&r_buffer_lock);
    if ( r_buffer )
    {
      v14 = *(void (**)(void))(r_buffer + 88);
      if ( *((_DWORD *)v14 - 1) != 1607364836 )
        __break(0x8228u);
      v14();
      v15 = *(void (**)(void))(r_buffer + 64);
      if ( *((_DWORD *)v15 - 1) != 251140989 )
        __break(0x8228u);
      v15();
    }
    mutex_unlock(&r_buffer_lock);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
