#pragma once
#include <stdint.h>
#include <socketapi.h>
using namespace std;

const char *ApiKey = { "5b91c8b88c01c3923d6fc3091acc1a8e12b26225" };

//OSU


/*  
class osuapi(k = undefined) {
	const base_url = `https://osu.ppy.sh/p/api/`;
		let api_key = k;

	let mix = {
		k: api_key,
	}
	async function get_user(user) {
		try {
			validateSettings();

			let endpoint = base_url.concat('get_user');

			user = Object.assign(mix, user);

			let postField = Object.keys(user).map(k = > `${k
		} = ${ user[k] }`).join('&')

				let request = await whateverYouUse(endpoint, postField);

			return {
				status: request.status,
				code : request.httpCode,
				content : (request.status == = 0) ? request.body : [];
			}

	}
	catch (Error) {

		return {
			status: -1,
			code : 114514,
			content : [];
		}
	}

}


function validateSettings() {
	if (api_key == = undefined) throw new Error('apikeyÄØ');
}
} */