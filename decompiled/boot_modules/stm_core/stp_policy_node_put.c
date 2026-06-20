__int64 __fastcall stp_policy_node_put(__int64 a1)
{
  mutex_unlock(&unk_440);
  return config_item_put(a1);
}
