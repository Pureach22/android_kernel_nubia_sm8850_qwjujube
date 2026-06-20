__int64 __fastcall qtee_shmbridge_query(__int64 a1)
{
  __int64 *v2; // x8
  unsigned int v3; // w19

  mutex_lock(&unk_13920);
  v2 = &bridge_list_head;
  while ( 1 )
  {
    v2 = (__int64 *)*v2;
    if ( v2 == &bridge_list_head )
      break;
    if ( v2[2] == a1 )
    {
      v3 = -17;
      goto LABEL_6;
    }
  }
  v3 = 0;
LABEL_6:
  mutex_unlock(&unk_13920);
  return v3;
}
