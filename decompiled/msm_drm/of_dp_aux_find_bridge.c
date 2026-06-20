_UNKNOWN **__fastcall of_dp_aux_find_bridge(void *a1)
{
  _UNKNOWN **v2; // x9
  _UNKNOWN **v3; // x19

  mutex_lock(&dp_aux_bridge_lock);
  v2 = &du_aux_bridge_list;
  while ( 1 )
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &du_aux_bridge_list )
      break;
    if ( *(v2 - 4) == a1 )
    {
      v3 = v2 - 4;
      goto LABEL_6;
    }
  }
  v3 = nullptr;
LABEL_6:
  mutex_unlock(&dp_aux_bridge_lock);
  return v3;
}
